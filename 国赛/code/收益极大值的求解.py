import numpy as np

import matplotlib.pyplot as plt

import pandas as pd

from scipy import signal

np.set_printoptions(threshold=np.inf)

plt.rcParams['font.sans-serif'] = 'SimHei'

df = pd.read_excel(r'..\data\C\附件3：银行贷款年利率与客户流失率关系的统计数据.xlsx')

print(df)


#定义x、y散点坐标

x = df['RATE']

x = np.array(x)

print('x is :\n',x)

num = df['A']

y1 = np.array(num)

print('y is :\n',y1)

y2 = df['B']

y3 = df['C']

#用3次多项式拟合

f1 = np.polyfit(x, y1, 3)

f2 = np.polyfit(x, y2, 3)

f3 = np.polyfit(x, y3, 3)

print('f1 is :\n',f1)

r = np.linspace(0.04,0.15,100)

jho1 = np.poly1d(f1)

jho2 = np.poly1d(f2)

jho3 = np.poly1d(f3)

p = 0.975
#y1 = 0.5*(2-jho1(r))*((1+r)*0.975-1)
y1 = (-1+(1+r)*1)*(1-jho1(r))

data1 = y1[signal.argrelextrema(y1, np.greater)]

print('A级用户的极值：',data1)


#y2 = 0.5*(2-jho2(r))*((1+r)*0.85-1)
y2 = (-1+(1+r)*0.973)*(1-jho2(r))

data2 = y2[signal.argrelextrema(y2, np.greater)]

print('B级用户的极值：',data2)

#y3 = 0.5*(2-jho3(r))*((1+r)*0.85-1)
y3 = (-1+(1+r)*0.941)*(1-jho3(r))

data3 = y3[signal.argrelextrema(y3, np.greater)]

print('C级用户的极值：',data3)

from sympy import *
a = symbols('a')
print('A级用户极值点：',solve(-f1[0]*(a**4)+f1[1]*(a**3)+f1[2]*(a**2)+(f1[3]+1)*a-data1,a))
print('B级用户极值点：',solve((-1+(1+a)*0.973)*(1-(f2[0]*(a**3)+f2[1]*(a**2)+f2[2]*a+f2[3]))-data2,a))
print('C级用户极值点',solve((-1+(1+a)*0.941)*(1-(f2[0]*(a**3)+f2[1]*(a**2)+f2[2]*a+f2[3]))-data3,a))



plt.plot(r,y1,label='A级用户两年期望收益平均值')

plt.plot(r,y2,label='B级用户两年期望收益平均值')

plt.plot(r,y3,label='C级用户两年期望收益平均值')

plt.legend()

plt.show()
