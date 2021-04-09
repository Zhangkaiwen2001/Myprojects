# -*- coding: utf-8 -*-


import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'
import tensorflow.compat.v1 as tf
tf.disable_v2_behavior()
import pandas as pd
import numpy as np
from sklearn.utils import shuffle
from sklearn.preprocessing import OneHotEncoder
import matplotlib.pyplot  as plt
from pylab import mpl

mpl.rcParams['font.sans-serif'] = ['SimHei']
df = pd.read_excel(r'..\data\C\分级训练集.xlsx')
df_test = pd.read_excel(r'..\data\C\分级测试集.xlsx')

train = []
target = []
for i in range(0, len(df['2017-2019销售额'])):
    mid = []
    mid.append(df['2017-2019销售额'][i])
    mid.append(df['2017-2019税负率%'][i])
    mid.append(df['2017-2019毛利率%'][i])
    mid.append(df['2017-2019进货额'][i])
    mid.append(df['退货率%'][i])
    mid.append(df['作废率%'][i])
    target.append(df['信誉'][i])
    train.append(mid)
train = np.array(train)
target = np.array(target)

test = []
test_target = []

for i in range(0, len(df_test['2017-2019销售额'])):
    mid = []
    mid.append(df_test['2017-2019销售额'][i])
    mid.append(df_test['2017-2019税负率%'][i])
    mid.append(df_test['2017-2019毛利率%'][i])
    mid.append(df_test['2017-2019进货额'][i])
    mid.append(df_test['退货率%'][i])
    mid.append(df_test['作废率%'][i])
    test_target.append(df_test['信誉'][i])
    test.append(mid)
test = np.array(test)
test_target = np.array(test_target)


train, target = shuffle(train, target)
target = target.reshape(-1, 1)
test_target = test_target.reshape(-1, 1)


enc = OneHotEncoder()
enc.fit(test_target)
test_target = enc.transform(test_target).toarray()
enc.fit(target)
target = enc.transform(target).toarray()
enc.fit(test_target)
print('Target',target)
print('test_target',test_target)


x = tf.placeholder(tf.float32, shape=(None, 6))
y = tf.placeholder(tf.float32, shape=(None, 4))
keep = tf.placeholder(tf.float32)


var1 = tf.Variable(tf.truncated_normal([6, 250], stddev=0.3))
bias1 = tf.Variable(tf.zeros([250]))
hc1 = tf.add(tf.matmul(x, var1), bias1)
h1 = tf.sigmoid(hc1)
h1 = tf.nn.dropout(h1, keep_prob=keep)


var2 = tf.Variable(tf.truncated_normal([250, 256], stddev=0.3))
bias2 = tf.Variable(tf.zeros([256]))
hc2 = tf.add(tf.matmul(h1, var2), bias2)
h2 = tf.sigmoid(hc2)
h2 = tf.nn.dropout(h2, keep_prob=keep)


var3 = tf.Variable(tf.truncated_normal([256, 4], stddev=0.3))
bias3 = tf.Variable(tf.zeros([4]))
hc3 = tf.add(tf.matmul(h2, var3), bias3)
h3 = tf.nn.softmax(hc3)


loss = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits_v2(logits=h3, labels=y))
tf.summary.scalar('loss', loss)


ac = tf.cast(tf.equal(tf.argmax(h3, 1), tf.argmax(y, 1)), tf.float32)
acc = tf.reduce_mean(ac)
tf.summary.scalar('accuracy', acc)


optimzer = tf.train.AdamOptimizer(1e-3).minimize(loss)
merge_summary = tf.summary.merge_all()
isTrain = 1

saver = tf.train.Saver(max_to_keep=1)

with tf.Session() as sess:
    if isTrain:
        init_op = tf.global_variables_initializer()
        sess.run(init_op)
        summary_writer = tf.summary.FileWriter('./logs/', sess.graph)
        nepoch = []
        trainacc = []
        testacc = []
        loss1 = []
        for i in range(0, 10001):

            sess.run(optimzer, feed_dict={x: train, y: target, keep: 0.5})
            train_summary = sess.run(merge_summary, feed_dict={x: train, y: target, keep: 1})
            summary_writer.add_summary(train_summary, i)

            if i % 50 == 0:
                accu = sess.run(acc, feed_dict={x: train, y: target, keep: 1})
                accuT = sess.run(acc, feed_dict={x: test, y: test_target, keep: 1})
                losss = sess.run(loss, feed_dict={x: train, y: target, keep: 1})

                print("epoch:" + str(i) + "   train_acc:" + str(accu) + "   test_acc:" + str(accuT) + "   loss:" + str(
                    losss))

                nepoch.append(i)
                trainacc.append(accu)
                testacc.append(accuT)
                loss1.append(losss)

        plt.title("BP神经网络训练性能曲线")
        plt.xlabel('训练次数')
        plt.ylabel('训练样本和检验样本的准确度')
        plt.plot(nepoch, trainacc, label='训练准确度')
        plt.plot(nepoch, testacc, label='测试准确度')
        plt.plot(nepoch, loss1,label='代价函数')
        plt.legend()
        # plt.plot(nepoch, trainacc, ,nepoch, loss1)
        plt.show()
