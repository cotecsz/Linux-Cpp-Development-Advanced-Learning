import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.cluster import KMeans
 
# 加载数据
wine = load_wine()

# 使用前两列作为聚类数据
X = wine.data[:, :2]
y = wine.target
y_pred = KMeans(n_clusters=3, random_state=9).fit_predict(X)

# 显示聚类结果
plt.scatter(X[:, 0], X[:, 1], c=y_pred)
plt.show()

# 显示真实类别结果
plt.scatter(X[:, 0], X[:, 1], c=y)
plt.show()