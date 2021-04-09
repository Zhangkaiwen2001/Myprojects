import torch

print('1: ', torch.cuda.is_available())  # 验证电脑是否存在GPU

ngpu = 1
device = torch.device("cuda:0" if (torch.cuda.is_available() and ngpu > 0) else "cpu")  # 选择运行设备

print('2: ', device)  # if条件满足，输出cuda:0; 不满足,输出 cpu
print('3: ', torch.cuda.current_device())  # 输出当前显卡的序号
print('4: ', torch.cuda.get_device_name())  # 获取电脑配备显卡的型号名称。括号内
print('5: ', torch.rand(3, 3).cuda())   # 将数据放到GPU上， 等同于  print(torch.rand(3,3).to(device))
print(torch.__version__)

