#!/usr/bin/python3
# -*-coding:utf-8 -*-

# @Time   : 2019/8/16 11:14
# @Author  : Yang Shuangzhen
# @File   : LogisticRegression.py

from sklearn import datasets
import matplotlib.pyplot as plt

iris = datasets.load_iris()
X = iris.data[:, :2]
y = (iris.target != 0) * 1

print('len(X):{length}, shape(X):{shape}'.format(length=len(X), shape=X.shape))
print('len(y):{length}, shape(y):{shape}'.format(length=len(y), shape=y.shape))

plt.scatter(X[:, :1], y, alpha=0.6)
plt.show()


