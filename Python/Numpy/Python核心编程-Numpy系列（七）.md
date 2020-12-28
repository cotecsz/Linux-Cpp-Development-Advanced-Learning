### Python核心编程-Numpy篇-第7节课



#### 本节课的OKR：

##### O：

- 理解矢量化编程（Vectorization）



##### KR：

- 写出真正的充分挥发Numpy性能的程序



---



#### Code Vectorization

##### 如何识别哪些任务可以进行Code Vectorization：

- 整个计算任务由多个相同性质的计算单元构成
- 在每次计算中，所有计算单元上执行的计算具有相同的抽象计算逻辑



##### 代码层面的矢量化编程要点：

- 计算单元
- 计算逻辑
- 空间条件
- 时间条件



##### 先来感受一下

``` python
>>> import numpy as np
>>> from random import sample
>>> from timeit import timeit
>>> def add_python(L1, L2):
...     return [x + y for (x, y) in zip(L1, L2)]
...
>>> def add_numpy(L1, L2):
...     return np.add(L1, L2)
...
>>> a = sample(range(10000), 1000)
>>> b = sample(range(10000), 1000)
>>> type(a)
<class 'list'>
>>> timeit("add_numpy(a, b)", globals=globals(), number=10000)
1.2160623630002192
>>> timeit("add_python(a, b)", globals=globals(), number=10000)
0.5947407849998854
```



##### 别慌

``` python
>>> def make_ndarray(L1, L2):
...     return np.array(L1), np.array(L2)
...
>>> arr_a, arr_b = make_ndarray(a, b)
>>> timeit("make_ndarray(a, b)", globals=globals(), number=10000)
1.1884412310000698
>>> timeit("add_numpy(arr_a, arr_b)", globals=globals(), number=10000)
0.011329727999964234
```



---



##### 用Numpy来实现一个简单的MaxPooling层

准备工作：

``` python
import numpy as np
from timeit import timeit

def timeit_100(s):
    print(timeit(s, globals=globals(), number=100))
```



迭代处理：

``` python
def maxpooling_iteration(x):
    y = np.empty((x.shape[-2] // 2, x.shape[-1] // 2), dtype=int)
    for i in range(x.shape[-2] // 2):
        for j in range(x.shape[-1] // 2):
            y[i, j] = np.max([x[2 * i, 2 * j],
                              x[2 * i + 1, 2 * j],
                              x[2 * i, 2 * j + 1],
                              x[2 * i + 1, 2 * j + 1]])
    return y
```



矢量化处理：

``` python
def maxpooling_vectorization(x):
    x = np.split(x, x.shape[-1] // 2, axis=-1)
    x = np.max(x, axis=-1)
    x = np.split(x, x.shape[-1] // 2, axis=-1)
    x = np.max(x, axis=-1)
    return x
```



看一下结果：

``` python
if __name__ == "__main__":
    x = np.arange(1000000).reshape((1000, 1000))
    timeit_100('maxpooling_iteration(x)')
    timeit_100('maxpooling_vectorization(x)')
```

``` python
176.918904601
1.1778114009999854
```



---



#### Problem Vectorization

问题：给定两个一维数组$X$、$Y$，对于其所有的索引$i、j$，求$\sum_{i,j} X[i] \times Y[j]$



``` py
def sum_xy_double_iteration(x, y):
    result = 0
    for i in x:
        for j in y:
            result += i * j
    return result
```



``` python
def sum_xy_broadcasting(x, y):
    return (x.reshape((1, x.size)) * y.reshape((y.size, 1))).sum()
```



``` python
def sum_xy_single_iteration_1(x, y):
    result = 0
    y_sum = 0
    for j in y:
        y_sum += j
    for i in x:
        result += y_sum * i
    return result
```



``` python
def sum_xy_single_iteration_2(x, y):
    x_sum = 0
    y_sum = 0
    for j in y:
        y_sum += j
    for i in x:
        x_sum += i
    return x_sum * y_sum
```



``` python
def sum_xy_vectorization(x, y):
    return x.sum() * y.sum()
```



``` python
if __name__ == "__main__":
    x = np.arange(1000)
    y = np.arange(1000, 2000)
    timeit_100('sum_xy_double_iteration(x, y)')
    timeit_100('sum_xy_broadcasting(x, y)')
    timeit_100('sum_xy_single_iteration_1(x, y)')
    timeit_100('sum_xy_single_iteration_2(x, y)')
    timeit_100('sum_xy_vectorization(x, y)')
```

``` python
14.779160522
0.23248548099999944
0.02869011499999985
0.02303162900000011
0.000639435000000077
```



##### Notes：

- $$\sum_{i,j} (x_i \times y_j) = \sum_i (x_i \times (\sum_j y_j)) = (\sum_i x_i) \times (\sum_j y_j)$$
- Problem层面的Vectorization，本质上是基于工具底层的理解，对数学和算法的Vectorization



---



#### Numpy Vectorization：

- 先考虑Problem Vectorization，然后，充分Code Vectorization

- 充分使用Numpy内置函数，能少用一个for算一个

  

---



#### 课程结束语：

- 编程的高手 = 对工具极深的理解 x 解决问题的能力 x 数学与算法的深厚功底
- 高效率学习 = $$ \max \frac{精力}{\frac1{产能} + \frac1{产出}}$$
- 不要迷失在Numpy，别忘了，还有Pandas，Scipy，scikit-learn
- TensorFlow 2.0 已发布，真正掌握Python与Numpy后，你会发现TensorFlow很简单

