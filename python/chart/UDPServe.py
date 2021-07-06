import socket
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(('', 5005))
while True:
    data, addr = s.recvfrom(1024)
    if not data:
        print("client has exited")
        break

    print('received:', data.decode("UTF-8"), 'from', addr)

s.close()