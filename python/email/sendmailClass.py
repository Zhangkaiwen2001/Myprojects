import smtplib
from email.header import Header
from email.mime.text import MIMEText


class SendMail:
    def __init__(self,stmp_host,mail_user,mail_pwd,toaddr,subject,context):
        #邮箱服务器信息
        self.__host=stmp_host
        self.__user=mail_user
        self.__pwd=mail_pwd
        #设置发送邮件内容
        self.__toaddr=toaddr.strip()
        self.__subject=subject.strip()
        self.__context=context.strip()
    def sendE(self):
        print("开始发送邮件......")
        msg=MIMEText(self.__context, 'plain', 'utf-8')  # 内容, 格式, 编码
        msg['Subject']=self.__subject
        msg['From']="{}".format(self.__user)
        msg['To']=self.__toaddr   #",".join(self.__toaddr)
        try:
            server=smtplib.SMTP_SSL(self.__host, 465)
            server.login(self.__user,self.__pwd)
            server.sendmail(self.__user,self.__toaddr,msg.as_string())
            print("Send successfully")
            server.quit()
        except smtplib.SMTPException as e:
            print(e)
            server.quit()
            return False
        return True
