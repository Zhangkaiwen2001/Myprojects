# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd


# df = pd.read_excel(r'..\data\C\document1.xlsx')
# data = df[['信誉评级','是否违约']]
# data[data == 'A'] = 1
# data[data == 'B'] = 2
# data[data == 'C'] = 3
# data[data == 'D'] = 4
# data[data == '否'] = 0
# data[data == '是'] = 1
# corr = data.corr()
# sns.heatmap(corr)
# plt.show()
plt.rcParams['font.sans-serif'] = 'SimHei'
plt.rcParams['axes.unicode_minus']=False
df = pd.read_excel(r'..\data\C\123家有信贷记录企业数据预处理.xlsx')
data = df[['2017-2019利润', '违约']]
data = data.replace('是', 1)
data = data.replace('否', 0)
pd.set_option('max_column', 100)
print(data)

#  建立logistics模型
from sklearn.linear_model import LogisticRegression as LR
x = data.iloc[:,:1].values
y = data.iloc[:,1].values
print('X:',x)
print('Y:',y,type(y))
lr = LR()
lr.fit(x, y)
print('模型的平均准确度为：%s' % lr.score(x, y))
print('模型相关系数: ',lr.coef_)
k = list(lr.coef_[0])
print(k, len(k))
def funcpPre(x):
    z = np.exp(k[0]*x[0])
    return z/(1+z)
print(lr)
data1 = []
for i in range(0,len(data)):
    number = data.iloc[i,:]
    data1.append(funcpPre(number))
    print(funcpPre(number))
print(data1, len(data1))
out = df[['信誉','2017-2019销售额', '2017-2019税负率%', '2017-2019毛利率%', '2017-2019进货额','违约','信誉']]
out['企业违约概率预测'] = data1[0:123]
print(out)
# out.to_excel(r'..\data\C\123家有信贷记录企业基本信息及违约概率预测.xlsx')

