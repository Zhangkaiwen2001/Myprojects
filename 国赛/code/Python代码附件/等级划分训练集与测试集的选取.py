# -*- coding: utf-8 -*-


import pandas as pd


df = pd.read_excel(r'..\data\C\123家有信贷记录企业数据预处理.xlsx')
df = df[['2017-2019销售额', '2017-2019税负率%', '2017-2019毛利率%', '2017-2019进货额','退货率%','作废率%', '信誉']]
df = df.replace('A', 0)
df = df.replace('B', 1)
df = df.replace('C', 2)
df = df.replace('D', 3)
data1 = df.sample(frac = 0.8)
df = df.append(data1)
data2 = df.drop_duplicates(subset=['2017-2019销售额', '2017-2019税负率%', '2017-2019毛利率%', '2017-2019进货额','退货率%','作废率%','信誉'],keep=False)
print('df: ', df)
print('data1: ', data1)
print('data:',data2)
print(pd.merge(data1,data2,on=['2017-2019销售额', '2017-2019税负率%', '2017-2019毛利率%', '2017-2019进货额','退货率%','作废率%','信誉']))
print(pd.merge(data1,data2,on=['2017-2019销售额', '2017-2019税负率%', '2017-2019毛利率%', '2017-2019进货额','退货率%','作废率%','信誉'],how='outer'))
data1.to_excel(r'..\data\C\分级测试集.xlsx')
data2.to_excel(r'..\data\C\分级训练集.xlsx')