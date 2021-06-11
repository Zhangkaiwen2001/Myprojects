import socket
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
port = 5005
host = '123.60.220.119'
while True:
    msg = input()
    if not msg:
        break
    s.sendto(msg.encode("UTF-8"), (host, port))

s.close()
