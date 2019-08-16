from sklearn.svm import SVR
from sklearn.datasets import load_boston
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error

# 加载数据
boston_dataset = load_boston()
y = boston_dataset.target
X = boston_dataset.data

# 将原始数据分为训练和测试数据
X_train, X_test, y_train, y_test = train_test_split(X,y)

# 定义模型
clf = SVR(C=1.0, epsilon=0.2)
# 在训练集上训练
clf.fit(X_train, y_train) 

# 测试
y_pred = clf.predict(X_test)

# 计算mse
mse_test = mean_squared_error(y_test, y_pred)
mse_train = mean_squared_error(y_train, clf.predict(X_train))

print('mse on testing data is:{}'.format(mse_test))
print('mse on training data is:{}'.format(mse_train))