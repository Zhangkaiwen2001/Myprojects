import numpy as np
import pandas as pd
from sklearn.linear_model import Lasso

df = pd.read_excel(r'..\data\C\123家有信贷记录企业数据预处理.xlsx')
lasso = Lasso(1000)
data = df[['2017-2019销售额', '2017-2019税负率%', '2017-2019毛利率%', '进货额', '退货率%','作废率%','违约']]
print(data)
data = data.replace('是', 1)
data = data.replace('否', 0)
print(data)
pd.set_option('max_column', 100)
data[data['2017-2019毛利率%'].isnull()] = 0.
print(data['2017-2019毛利率%'])
print(data.describe())
lasso.fit(data.iloc[:,0:6],data['违约'])
sign = lasso.coef_ != 0
print('相关系数是否为零：', sign)
print('相关系数为：',np.round(lasso.coef_, 5))
new_data = data.iloc[:, sign]
new_data.to_excel(r'..\data\C\lasso系数分析.xlsx')
print('输出数据的维度: ',new_data.shape)
