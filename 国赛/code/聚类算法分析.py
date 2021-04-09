# -*- coding: utf-8 -*-
import pandas as pd

kinds = 4
iteration = 1000
df = pd.read_excel(r'..\data\C\123家有信贷记录企业数据预处理.xlsx')
data = df[['2017-2019进货额','2017-2019利润','2017-2019税负率%','2017-2019毛利率%','退货率%','作废率%','信誉']]
data = data.replace('A', 0)
data = data.replace('B', 1)
data = data.replace('C', 2)
data = data.replace('D', 3)
# data = data.replace('是', 1)
# data = data.replace('否', 0)
data.dropna(axis=0, how='any', inplace=True)

data['2017-2019利润'] = 1.0* (data['2017-2019利润'] - data['2017-2019利润'].mean()) / data['2017-2019利润'].std()
# data['2017-2019销售额'] = 1.0 * (data['2017-2019销售额'] - data['2017-2019销售额'].mean()) / data['2017-2019销售额'].std()
data['2017-2019税负率%'] = 1.0 * (data['2017-2019税负率%'] - data['2017-2019税负率%'].mean()) / data['2017-2019税负率%'].std()
data['2017-2019毛利率%'] = 1.0 * (data['2017-2019毛利率%'] - data['2017-2019毛利率%'].mean()) / data['2017-2019毛利率%'].std()
data['2017-2019进货额'] = 1.0 * (data['2017-2019进货额'] - data['2017-2019进货额'].mean()) / data['2017-2019进货额'].std()
data['退货率%'] = 1.0 * (data['退货率%'] - data['退货率%'].mean()) / data['退货率%'].std()
data['作废率%'] = 1.0 * (data['作废率%'] - data['作废率%'].mean()) / data['作废率%'].std()
data['信誉'] = 1.0 * (data['信誉'] - data['信誉'].mean()) / data['信誉'].std()
# data['违约'] = 1.0 * (data['违约'] - data['违约'].mean()) / data['违约'].std()
from sklearn.cluster import KMeans
from sklearn.manifold import TSNE
if __name__ == '__main__':
    model = KMeans(n_clusters=kinds, max_iter=iteration, random_state=1234)
    model.fit(data)


    r1 = pd.Series(model.labels_).value_counts()
    r2 = pd.DataFrame(model.cluster_centers_)
    r = pd.concat([r2, r1], axis=1)
    r.columns = list(data.columns) + ['分类数目']
    print(r)


    r = pd.concat([data, pd.Series(model.labels_, index=data.index)], axis=1)
    r.columns = list(data.columns) + ['聚类类别']
    r.to_excel(r'..\data\C\聚类分析结果.xlsx')


    tsne = TSNE(random_state=100)
    tsne.fit_transform(data)
    tsne = pd.DataFrame(tsne.embedding_, index = data.index)

    import matplotlib.pyplot as plt
    plt.rcParams['font.sans-serif'] = ['SimHei']
    plt.rcParams['axes.unicode_minus'] = False


    d = tsne[r['聚类类别'] == 0]
    plt.plot(d[0], d[1], 'r.')
    d = tsne[r['聚类类别'] == 1]
    plt.plot(d[0], d[1], 'go')
    d = tsne[r['聚类类别'] == 2]
    plt.plot(d[0], d[1], 'b*')
    d = tsne[r['聚类类别'] == 3]
    plt.plot(d[0], d[1], 'k^')
    plt.savefig(r'..\data\C\图片\聚类分析企业供求关系图.jpg')
    plt.show()


