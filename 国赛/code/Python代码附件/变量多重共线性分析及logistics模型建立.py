# -*- coding: utf-8 -*-


import matplotlib.pyplot as plt
import pandas as pd


plt.rcParams['font.sans-serif'] = 'SimHei'
plt.rcParams['axes.unicode_minus']=False
df = pd.read_excel(r'..\data\C\123家有信贷记录企业数据预处理.xlsx')
data = df[['信誉','2017-2019税负率%', '2017-2019进货额', '2017-2019毛利率%','退货率%','违约']]
data = data.replace('A', 0)
data = data.replace('B', 1)
data = data.replace('C', 2)
data = data.replace('D', 3)
data = data.replace('是', 1)
data = data.replace('否', 0)
data[data['2017-2019毛利率%'].isnull()] = 0.
pd.set_option('max_column', 100)
print(data)
corr = data.corr(method='pearson')


import seaborn as sns
plt.subplots(figsize=(10, 10)) # 设置画面大小
sns.heatmap(corr, annot=True, vmax=1, square=True, cmap='Reds')
plt.savefig(r'..\data\C\图片\各变量相关系数热力图.jpg', dpi = 600)
plt.show()

#  建立logistics模型
from sklearn.linear_model import LogisticRegression as LR
x = data.iloc[:,:5].values
y = data.iloc[:,5].values
print('X:',x)
print('Y:',y,type(y))
lr = LR()
lr.fit(x, y)
print('模型的平均准确度为：%s' % lr.score(x, y))
print('模型相关系数: ',lr.coef_)
print(lr.predict(x))
out = df[['信誉','2017-2019销售额', '2017-2019税负率%', '2017-2019毛利率%', '2017-2019进货额','违约','信誉']]
out['企业是否违约预测'] = lr.predict(x)
out.to_excel(r'..\data\C\123家有信贷记录企业基本信息及违约预测.xlsx')

