import smtplib
import email


def prompt(pmt):
    return input(pmt).strip()


fromaddr = prompt("From:")
toaddr = prompt("To:")
subject = prompt("Subject:")
print("Enter message, end with continuously enter:")
text = ""
while True:
    try:
        line = input()
    except EOFError:
        break
    if len(line) == 0:
        break
    text = text + line + "\r\n"
    msg = email.message_from_string(text)
    msg['Subject'] = subject
    msg['From'] = fromaddr
    msg['To'] = toaddr
    msg.set_charset('GB2312')
    server = smtplib.SMTP('smtp.163.com')
    user = fromaddr
    pwd = input('请输入邮箱密码:')  # TZAPWCEXAQIAGRHR
    server.login(user, pwd)
    server.send_message(msg, fromaddr, toaddr)
    print("Send successfully")
    server.quit()
