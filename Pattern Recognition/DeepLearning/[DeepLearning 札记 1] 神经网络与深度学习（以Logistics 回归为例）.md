# [DeepLearning 札记 1] 神经网络与深度学习（以Logistics 回归为例）

​    

系列学习笔记用于记录神经网络基础。

本篇笔记通过二分类问题来实现简单的神经网络，简单介绍二分类问题，使用`Logistic Regression` 算法进行分类，**实现深度学习算法的基本流程**。对 ` Hypothesis Function` ， `Sigmoid Function` ，`Cost Function` 进行简单介绍与实现。

[TOC]

## Symbol Description

|                 符号                  | 描述                                                   |
| :-----------------------------------: | :----------------------------------------------------- |
|                 $$X$$                 | 表示一个$$n_{x}$$维数据，为输入数据，纬度为$(n_{x},1)$ |
|                  $Y$                  | 表示输出结果， 取值为$(0,1)$                           |
|         $(x^{(i)}, y^{(i)})$          | 表示第$i$组数据，默认为训练数据                        |
| $X = [x^{(1)}, x^{(2)}, ……, x^{(m)}]$ | 表示所有训练数据的输入值，纬度为$(n_{x}， m)$          |
| $Y = [y^{(1)}, y^{(2)}, ……, y^{(m)}]$ | 表示对应所有训练数据集的输出值，纬度为$(1, m)$         |
|              $M_{train}$              | 训练集的样本数                                         |
|              $M_{test}$               | 测试集的样本数                                         |



## Binary Classification

​      分类问题：假设有一个图片作为输入，判断图片中是否为猫，若是猫，则输出标签`1`作为结果；若识别不是猫，则输出标签`0`作为结果。下面通过`logistic regression`来解决二分类问题。



## Logistic Regression

### Hypothesis Function

​        假设函数（Hypothesis Function）是对于抽象问题的建模，通过假设函数，可以得到预测值 $\hat{y}$ ，对于不同的问题，使用的假设函数不通。在二分类问题中，使用`Logistic Regression`进行预测，在多分类问题中，使用`softmax Regression`模型进行预测。

​        对于二分类问题，给定一个输入向量$X$, 通过算法 `A` 输出 $\hat{y}$ 来预测图片中是否为猫，这里$\hat{y}$ 是对于实际值 $y$ 的预测。首先，假设函数为线性函数 $\hat{y} = w^{T}x + b$ , 那么$\hat{y}$ 的输出值范围为$(-\infty, +\infty)$ ， 而在二分类问题中，需要预测的是$y == 1$ 的概率，$\hat{y} \in [0, 1]$ ,所以将线性函数转化为非线性函数。



### Sigmod function

| 名称 | 描述                         |
| :--: | :--------------------------- |
| 公式 | $\sigma(z) = 1 / (1+e^{-z})$ |
| 值域 | $(0, 1)$                     |

sigmoid图像如下：

![sigmoid](./images/sigmoid_function.png)

sigmod代码实现：

```python
import numpy as np
import matplotlib.pyplot as plt

def sigmoid(x):
  ''' Sigmoid function.
  
  Args:
  	x : input data
  
  Return:
		the sigmoid value.
  '''
  return 1.0/(1+np.exp(-x))
 
sigmoid_inputs = np.arange(-10,10,0.1)
sigmoid_outputs = sigmoid(sigmoid_inputs)
print("Sigmoid Function Input :: {}".format(sigmoid_inputs))
print("Sigmoid Function Output :: {}".format(sigmoid_outputs))
 
plt.plot(sigmoid_inputs,sigmoid_outputs)
plt.xlabel("Sigmoid Inputs")
plt.ylabel("Sigmoid Outputs")
plt.show()
```



这里，假设函数是
$$
\begin{equation}  
\left\{  
         \begin{array}
             \hat{y} = \sigma(w^{T}x + b) \\
						 \sigma(z) = 1 / (1+e^{-z})   
         \end{array}  
\right.  
\end{equation}
$$
用**向量 $\theta = [\theta_0, \theta_1, ..., \theta_{n_x}]$ 表示参数 , $\theta_0$ 替代参数 $b$ ，$\theta_0, \theta_1, ..., \theta_{n_x}$ 替代 $w$ ** , 令$ x_0 = 1$, 则
$$
\hat{y} = \sigma(\theta^{T}x) \
$$


### Cost Function and Loss Function

​        在上节中，通过 **假设函数** 预测出 $\hat{y}$ ，但是并不知道 $\hat{y}$ 与 $y$ 得接近程度， 对于单个样本 $ (x^{(m)}, y^{(m)})$ ，使得 $\hat{y} \approx y$ ，损失函数用于衡量预测值与真实值之间的接近程度；对于多个样本，通过代价函数来衡量预测输出值和实际值的接近程度。通俗来说，Loss Function是对于单个样本的损失函数，Cost Function是对于多个样本的损失函数，即对多个样本的代价函数取均值。



​        在Logistic Regression中，单个样本损失函数为：
$$
L(\hat{y}, y) = -ylog(\hat{y}) - (1 - y)log(1 - \hat{y})
$$
​         m个样本的代价函数为：
$$
J(w, b) = \frac{1}{m}\sum_{i=1}^m{(-y^{(i)}log \hat{y}^{(i)}) - (1-y^{(i)}) log(1 - \hat{y}^{(i)}))}
$$

> 代价函数是对于参数的总代价，在训练模型时，使得总代价 $J$ 最小。 



### Gradient Descent

​        在测试集上，可以通过最小化代价函数 $ J(w, b)$ 来训练参数 $w$ 和 $b$ ，通过尝试不同的参数使得代价函数最小，有没有更好的办法求得参数？**梯度下降法** （Gradient Descent）是一种常见的最小化函数的方法，比如最小均方误差（Mean Squared Error, MSE）损失函数。

​        通过初始化参数 $\theta$ ，











## Reference

1.  [代价函数详解](https://www.cnblogs.com/Belter/p/6653773.html)
2. 








