# -*- coding: utf-8 -*-


import pandas as pd
import matplotlib.pyplot as plt


plt.rcParams['font.sans-serif'] = 'SimHei'
df = pd.read_excel(r'..\data\C\第二问分析及结论数据.xlsx')
data = df['信誉']
rank1 = 0
rank2 = 0
rank3 = 0
rank4 = 0
for i in data:
    if i == 'A':
        rank1 = rank1 + 1
    elif i == 'B':
        rank2 = rank2 + 1
    elif i == 'C':
        rank3 = rank3 + 1
    else:
        rank4 = rank4 + 1

count1 = rank1 / len(data)
count2 = rank2 / len(data)
count3 = rank3 / len(data)
count4 = rank4 / len(data)


count = [count1, count2, count3, count4]
Label = ['A级占比', 'B级占比', 'C级占比', 'D级占比']
explode=[0.04, 0.03, 0.02, 0.01]

plt.pie(count, explode=explode, labels=Label, autopct='%.1f%%')
plt.savefig(r'..\data\C\图片\等级预测饼图',dpi=600)
plt.show()