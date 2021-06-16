from tkinter import *  # 引用Tk模块
from tkinter.messagebox import *
from sendmailClass import SendMail

root = Tk()  # 初始化Tk()
root.title("发邮件")
frm = Frame(root)
root.geometry('470x320')


def get_context():
    rec_text = var_receiver.get()
    send_text = var_sender.get()
    ti_text = var_title.get()
    con_text = t_show.get('1.0', END)
    if rec_text == '':
        showinfo('提示', "接收人不能为空")
        return
    s = SendMail("smtp.163.com", send_text, 'TZAPWCEXAQIAGRHR', rec_text, ti_text, con_text)
    if s.sendE():
        showinfo('提示', "发送成功")
    else:
        showinfo('提示', "发送失败")


def savemail():
    try:
        with open("D:\\Myprojects\\python\\mailfile.txt", 'w') as f:
            f.write(var_receiver.get() + "\n")
            f.write(var_sender.get() + "\n")
            f.writelines(var_title.get() + "\n")
            f.write(t_show.get('1.0', END))
            showinfo('提示', "暂存邮件成功")
    except:
        print('文件创建失败')
        showinfo('提示', "文件创建失败")


def readmail():
    try:
        with open("D:\\Myprojects\\python\\mailfile.txt", 'r') as f:
            clear()
            receiver = f.readline()
            print(receiver)
            var_receiver.set(receiver)
            sender = f.readline()
            var_sender.set(sender)
            title = f.readline()
            var_title.set(title)
            context = f.read()
            t_show.insert('1.0', context)
    except:
        print('文件读取失败')
        showinfo('提示', "文件创建失败")


def clear():
    var_receiver.set('')
    var_sender.set('')
    var_title.set('')
    t_show.delete('1.0', '10.0')


frm_S = Frame(frm)
Button(frm_S, text="发送", command=get_context, width=6, height=1, font=('Arial', 10)).pack(side=LEFT)
Button(frm_S, text="重置", command=clear, width=6, height=1, font=('Arial', 10)).pack(side=LEFT)
Button(frm_S, text="暂存", command=savemail, width=6, height=1, font=('Arial', 10)).pack(side=RIGHT)
Button(frm_S, text="读取", command=readmail, width=6, height=1, font=('Arial', 10)).pack(side=RIGHT)
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
t_show = Text(frm_M, width=34, height=6, font=('Verdana', 15))
t_show.insert('1.0', 'Hello,Calvin')
t_show.pack()
frm_M.pack()

frm.pack()
root.mainloop()
