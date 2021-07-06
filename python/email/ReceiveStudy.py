from tkinter import *  # 引用Tk模块
from tkinter.messagebox import *
from receivemail import *

root = Tk()  # 初始化Tk()
root.title("收邮件")
frm = Frame(root)
root.geometry('470x320')


def readmail():
    email = '3252257325@qq.com'
    password = 'ubcphgbixniicjib'

    server = poplib.POP3_SSL('pop.qq.com')
    server.user(email)
    server.pass_(password)
    try:
        # 登录的过程
        resp, mails, octets = server.list()
        index = len(mails)  # 邮件的总数
        # 此处的循环是取最近的几封邮件
        for i in range(index -1, index):
            resp, lines, octets = server.retr(i)  # 取邮件
            msg_content = b'\r\n'.join(lines).decode('utf-8', 'ignore')
            msg = Parser().parsestr(msg_content)
            # server.dele(index) 删除邮件
            for header in ['From', 'To', 'Subject']:
                value = msg.get(header, '')
                if value:
                    # 文章的标题有专门的处理方法
                    if header == 'Subject':
                        value = decode_str(value)
                        var_title.set(value)
                    elif header == 'From':
                        # 地址也有专门的处理方法
                        hdr, addr = parseaddr(value)
                        name = decode_str(addr)
                        # value = name + ' < ' + addr + ' > '
                        value = name
                        var_sender.set(value)
                    else:
                        # 地址也有专门的处理方法
                        hdr, addr = parseaddr(value)
                        name = decode_str(addr)
                        # value = name + ' < ' + addr + ' > '
                        value = name
                        var_receiver.set(value)
            get_file(msg)
            for part in msg.walk():
                content_type = part.get_content_type()
                charset = guess_charset(part)
                # 如果有附件，则直接跳过
                if part.get_filename() != None:
                    continue
                email_content_type = ''
                content = ''
                if content_type == 'text/plain':
                    email_content_type = 'text'
                elif content_type == 'text/html':
                    continue  # 不要html格式的邮件
                    email_content_type = 'html'
                if charset:
                    try:
                        content = part.get_payload(decode=True).decode(charset)
                    except AttributeError:
                        print('type error')
                    except LookupError:
                        print("unknown encoding: utf-8")
                if email_content_type == '':
                    continue
                    # 如果内容为空，也跳过
                t_show.insert('1.0', email_content_type + ' -----  ' + content)
        server.quit()
    except:
        print('邮件读取失败')
        showinfo('提示', "邮件读取失败")


def clear():
    var_receiver.set('')
    var_sender.set('')
    var_title.set('')
    t_show.delete('1.0', '1000.0')


frm_S = Frame(frm)
Button(frm_S, text="接收", command=readmail, width=6, height=1, font=('Arial', 10)).pack(side=RIGHT)
Button(frm_S, text="清空", command=clear, width=6, height=1, font=('Arial', 10)).pack(side=LEFT)
frm_S.pack(side=TOP)

frm_L = Frame(frm)
frm_LT = Frame(frm_L)
Label(frm_LT, text='发件人', font=('Arial', 12)).pack(side=TOP)
Label(frm_LT, text='接收人', font=('Arial', 12)).pack(side=TOP)
Label(frm_LT, text='  题目', font=('Arial', 12)).pack(side=TOP)
frm_LT.pack(side=LEFT)
frm_RT = Frame(frm_L)
var_sender = StringVar()
var_title = StringVar()
var_receiver = StringVar()
Entry(frm_RT, textvariable=var_sender, width=30, font=('Verdana', 15)).pack()
Entry(frm_RT, textvariable=var_receiver, width=30, font=('Verdana', 15)).pack()
Entry(frm_RT, textvariable=var_title, width=30, font=('Verdana', 15)).pack()
frm_RT.pack(side=RIGHT)
frm_L.pack(side=TOP)

# third-label
frm_ConText = Frame(frm)
Label(frm_ConText, text='发送内容', font=('Arial', 12)).pack(side=TOP)
frm_ConText.pack(side=TOP)

# forth-inputcontext
frm_M = Frame(frm)
t_show = Text(frm_M, width=960, height=540, font=('Verdana', 15))
t_show.insert('1.0', 'Hello,Calvin')
t_show.pack()
frm_M.pack()

frm.pack()
root.mainloop()
