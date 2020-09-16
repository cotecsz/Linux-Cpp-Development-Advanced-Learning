from sklearn import linear_model
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.datasets import load_iris

# 加载数据
iris = load_iris()

# 使用前两列作为原始数据
X = iris.data[:, :2]
y = iris.target

# 将原始数据分为训练和测试数据
X_train, X_test, y_train, y_test = train_test_split(X,y)

print("训练数据的维度为:",X_train.shape)
print("测试数据的维度为:",X_test.shape)

# 构建分类器
clf = linear_model.LogisticRegression(C=1e5)
# 训练
clf = clf.fit(X_train, y_train)

# 测试
y_pred = clf.predict(X_test)

# 测试模型的准确率
acc = accuracy_score(y_test,y_pred)

print('accuracy is: {}'.format(acc))