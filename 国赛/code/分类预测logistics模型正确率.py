# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt
import pandas as pd

plt.rcParams['font.sans-serif'] = 'SimHei'
plt.rcParams['axes.unicode_minus']=False
df = pd.read_excel(r'..\data\C\123家有信贷记录企业数据预处理.xlsx')
data = df[['信誉','17-19收入', '17-19增值税', '税负率%', '退货率%', '作废率%', '违约']]
data = data.replace('是', 1)
data = data.replace('否', 0)


# from sklearn.linear_model import LogisticRegression as LR
# x = data.iloc[:,:5].values
# y = data.iloc[:,5].values
# lr = LR()
# lr.fit(x, y)
data1 = data[data['违约'] == 1]
data2 = data[data['违约'] == 0]