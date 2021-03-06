
import cv2
import os
import time
show_heigth = 40
show_width = 80

# ascii_char = list("$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|
# ()1{}[]?-_+~<>i!lI;:,\"^`'. ")
ascii_char = list("*/.")
# 生成一个ascii字符列表
char_len = len(ascii_char)

vc = cv2.VideoCapture("F:\\video\\BAD APPLE 1080P.mp4")          # 加载一个视频

if vc.isOpened():                       # 判断是否正常打开
    rval, frame = vc.read()
else:
    rval = False

frame_count = 0
outputList = []                         # 初始化输出列表
while rval:   # 循环读取视频帧
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)  # 使用opencv转化成灰度图
    gray = cv2.resize(gray, (show_width, show_heigth))  # resize灰度图
    text = ""
    for pixel_line in gray:
        for pixel in pixel_line:                    # 字符串拼接
            text += ascii_char[int(pixel / 256 * char_len)]
        text += "\n"
    outputList.append(text)
    frame_count = frame_count + 1
    if frame_count % 100 == 0:
        print("已处理" + str(frame_count) + "帧")
    rval, frame = vc.read()
print("处理完毕")

for frame in outputList:
    os.system("cls")                    # 清屏
    print(frame)
    print()
    print()
    time.sleep(0.01)              # 输出过快时可适当暂停
