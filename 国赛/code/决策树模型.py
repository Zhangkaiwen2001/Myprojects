import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score
from sklearn.tree import DecisionTreeClassifier


pd.set_option('display.max_columns', None)
df = pd.read_excel(r'..\data\C\分级训练集.xlsx')
df_test = pd.read_excel(r'..\data\C\分级测试集.xlsx')


data = df.iloc[:,:7]
print('data:',data.describe())
label = df.iloc[:,7]
print('label',label.describe())

data_test = df_test.iloc[:,:7]
print('data_test:',data.describe())
label_test = df_test.iloc[:,7]
print('label_test',label.describe())
data_test.dropna(axis=0, how='any')

model = DecisionTreeClassifier(random_state=5).fit(data, label)

pre_test = model.predict(data_test)

cm_test = confusion_matrix(label_test,pre_test)
print(cm_test)

print(accuracy_score(label_test, pre_test))