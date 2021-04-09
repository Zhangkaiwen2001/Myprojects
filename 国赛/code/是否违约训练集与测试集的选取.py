import pandas as pd


df = pd.read_excel(r'..\data\C\123家有信贷记录企业数据预处理.xlsx')
df = df[['2017-2019销售额', '2017-2019税负率%', '2017-2019毛利率%', '2017-2019进货额','退货率%','作废率%','违约']]
df = df.replace('是', 1)
df = df.replace('否', 0)
data1 = df.sample(frac = 0.8)
df = df.append(data1)
data2 = df.drop_duplicates(subset=['2017-2019销售额', '2017-2019税负率%', '2017-2019毛利率%', '2017-2019进货额','退货率%','作废率%','违约'],keep=False)
print('df: ', df)
print('data1: ', data1)
print('data:',data2)
print(pd.merge(data1,data2,on=['2017-2019销售额', '2017-2019税负率%', '2017-2019毛利率%', '2017-2019进货额','退货率%','作废率%','违约']))
print(pd.merge(data1,data2,on=['2017-2019销售额', '2017-2019税负率%', '2017-2019毛利率%', '2017-2019进货额','退货率%','作废率%','违约'],how='outer'))
data1.to_excel(r'..\data\C\是否违约测试集.xlsx')
data2.to_excel(r'..\data\C\是否违约训练集.xlsx')