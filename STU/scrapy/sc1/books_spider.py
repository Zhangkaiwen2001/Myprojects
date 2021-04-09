# -*-coding -: utf8 _*-
import scrapy


class BookSpider(scrapy.Spider):
    # 爬虫名字
    name = 'books'
    # 爬虫的起点，可以是多个
    start_urls = [r'http://books.toscrapy.com/']

    def parse(self, response):
        # 提取数据
        # 每一本书的信息在<article.product_pod'>中，我们使用css()方法找到这样的article元素，并进行迭代
        for book in response.css('article.product_pod'):
            # 书名信息在article > h3 > a 元素的title属性里
            name = book.xpath('./h3/a/@title').extract_first()

            # 书价信息在<p class="price_color")的text中
            price = book.css('p.price_color::text').extract_first()
            yield {
                'name': name,
                'price': price,
            }

        # 提取链接，下一页的url在ul.pager >li.next >a : 里面
        next_url = response.css('ul.pager li.next a::attr(href)').extract_first()
        if next_url:
            # 如果找到下一页的url，得到绝对路径后，构造新的request对象
            next_url = response.urljoin(next_url)
            yield scrapy.Request(next_url, callback=self.parse)


