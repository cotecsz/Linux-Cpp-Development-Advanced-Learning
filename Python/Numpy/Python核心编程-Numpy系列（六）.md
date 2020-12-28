### Python核心编程-Numpy篇-第6节课



#### 本节课的OKR：

##### O：

- 能用Numpy快速进行通用的数据处理流程
- 使用Numpy的时候能充分发挥每个基础函数真实的威力



##### KR：

- 可以灵活的使用Numpy进行数据聚合
- 能清晰的指出要操作的是哪个轴
- 进一步体会就地修改与重新创建的区别
- 进一步体会View与Copy的差异
- 进一步体会ndarray的高级索引的优势



---



#### 随机数

##### 随机数的产生

``` python
>>> import numpy as np
>>> from numpy import random as nr
>>> np.set_printoptions(precision=2)
>>> r1 = nr.rand(3,4)
>>> r2 = nr.randn(3,4)
>>> r3 = nr.randint(1,11,(3,4))
>>> r1
array([[0.5 , 0.35, 0.6 , 0.93],
       [0.85, 1.  , 0.87, 0.98],
       [0.58, 0.07, 0.29, 0.92]])
>>> r2
array([[ 0.01, -1.04, -0.39, -1.4 ],
       [-1.03, -1.15, -0.46, -0.2 ],
       [ 0.51,  0.47, -0.38,  0.16]])
>>> r3
array([[10,  8,  1,  5],
       [10, 10, 10,  4],
       [ 9,  5,  7,  7]])
```

##### Notes：

- rand：0-1之间的随机数，参数全部用于描述结果的shape
- randn：标准正态分布，参数全部用于描述结果的shape
- randint：从指定整数范围内随机选取整数，参数：`(start, end, shape)`



##### 服从某一分布的随机数组的产生

``` python
>>> nr.normal(100, 10, (3,4))
array([[ 97.52, 100.24,  99.74, 111.84],
       [102.88, 104.37,  99.38, 100.35],
       [ 91.63, 109.91, 100.2 ,  95.07]])
>>> nr.uniform(10, 20, (3,4))
array([[19.5 , 11.93, 11.07, 18.31],
       [11.03, 14.23, 17.66, 18.46],
       [13.46, 13.71, 18.77, 17.6 ]])
>>> nr.poisson(2.0, (3,4))
array([[2, 0, 3, 5],
       [0, 3, 0, 4],
       [2, 2, 3, 1]])
```

##### Notes：

- normal：通用正态分布
- uniform：均匀分布
- poisson：泊松分布（单位时间或单位面积内，随机事件的平均发生率）



##### 随机排列

``` python
>>> nr.permutation(6)
array([4, 5, 2, 3, 1, 0])
>>> nr.permutation(np.arange(-3,7,2))
array([ 3, -3, -1,  1,  5])
>>> nr.permutation(np.arange(6).reshape((2,3)))
array([[3, 4, 5],
       [0, 1, 2]])

>>> r1 = np.arange(6)
>>> r2 = np.arange(12).reshape((3,4))
>>> nr.shuffle(r1)
>>> nr.shuffle(r2)
>>> r1
array([3, 5, 4, 2, 1, 0])
>>> r2
array([[ 8,  9, 10, 11],
       [ 0,  1,  2,  3],
       [ 4,  5,  6,  7]])
```



##### 随机选取

``` python
>>> a = np.arange(12)
>>> r1 = nr.choice(a, size=(2,3))
>>> r2 = nr.choice(a, size=(2,3), replace=False)
>>> r3 = nr.choice(a, size=(2,3), replace=False, p=a/a.sum())
>>> r1
array([[ 5,  1,  3],
       [11, 10,  1]])
>>> r2
array([[2, 5, 9],
       [6, 3, 0]])
>>> r3
array([[10,  2,  4],
       [ 9,  8,  6]])
```

##### Notes：

- replace：是否可重复抽取
- p：指定每个元素被抽取到的概率



##### 随机数种子

``` python
>>> r1 = nr.randint(0,10,(3,4))
>>> r2 = nr.randint(0,10,(3,4))
>>> nr.seed(2019)
>>> r3 = nr.randint(0,10,(3,4))
>>> nr.seed(2019)
>>> r4 = nr.randint(0,10,(3,4))
>>> r1
array([[7, 0, 9, 1],
       [7, 7, 0, 2],
       [7, 9, 4, 1]])
>>> r2
array([[3, 3, 8, 1],
       [2, 9, 4, 9],
       [1, 8, 8, 1]])
>>> r3
array([[8, 2, 5, 8],
       [6, 8, 0, 0],
       [7, 8, 5, 3]])
>>> r4
array([[8, 2, 5, 8],
       [6, 8, 0, 0],
       [7, 8, 5, 3]])
```

##### Notes：

- 若要结果可以复现，需要控制随机种子



---



#### 求和、均值、方差

##### 对序列求和：`np.sum()`(包括Python序列和Numpy的ndarray)

``` python
>>> np.sum([x for x in range(10)])
45
>>> np.sum(range(10))
45
>>> np.sum(np.arange(10))
45
>>> np.sum(np.arange(10).reshape((2,5)))
45
```



##### 基于指定轴的求和：参数`axis`

``` python
>>> x = np.arange(24).reshape(2,3,4)
>>> x
array([[[ 0,  1,  2,  3],
        [ 4,  5,  6,  7],
        [ 8,  9, 10, 11]],

       [[12, 13, 14, 15],
        [16, 17, 18, 19],
        [20, 21, 22, 23]]])
>>> np.sum(x, axis=0)
array([[12, 14, 16, 18],
       [20, 22, 24, 26],
       [28, 30, 32, 34]])
>>> np.sum(x, axis=1)
array([[12, 15, 18, 21],
       [48, 51, 54, 57]])
>>> np.sum(x, axis=2)
array([[ 6, 22, 38],
       [54, 70, 86]])
```



##### 对多个轴进行求和：

``` python
>>> x
array([[[ 0,  1,  2,  3],
        [ 4,  5,  6,  7],
        [ 8,  9, 10, 11]],

       [[12, 13, 14, 15],
        [16, 17, 18, 19],
        [20, 21, 22, 23]]])
>>> np.sum(x, axis=(0,2))
array([ 60,  92, 124])
>>> np.sum(x, axis=(0,2), keepdims=True)
array([[[ 60],
        [ 92],
        [124]]])
>>> _.ndim
3
```



##### 类型，及累加变量的溢出与精度问题

``` python
>>> x = np.arange(10, dtype='i1')
>>> x
array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9], dtype=int8)
>>> np.sum(x).dtype
dtype('int64')

>>> x = np.full(1000000, 1.1, dtype='f4')
>>> np.sum(x) - 1100000
-0.75
>>> np.sum(x, dtype='f8') - 1100000
0.02384185791015625
```

##### Notes：

- 32位系统中，默认int类型是32位，大范围累加会有溢出风险
- 单精度浮点数持续累加，最好把累加变量设为双精度浮点，以降低累计误差



##### 均值函数`np.mean()`与求和函数在使用方法上基本相同

``` python
>>> x = np.arange(10)
>>> x.dtype
dtype('int64')
>>> np.mean(x)
4.5
>>> np.mean(x).dtype
dtype('float64')
```

##### Notes：

- 区别在于，中间变量的类型
- `np.product()`也是类似



##### 加权平均：`np.average()`

``` python
>>> a = np.array([1,10,100])
>>> b = np.arange(1,4)
>>> a
array([  1,  10, 100])
>>> b
array([1, 2, 3])
>>> np.average(b, weights=a)
2.891891891891892
```



##### 标准差，无偏样本方差，偏样本方差

``` python
>>> x = np.arange(5)
>>> np.std(x)
1.4142135623730951
>>> np.var(x)
2.0
>>> np.std(x, ddof=1)
1.5811388300841898
>>> np.var(x, ddof=1)
2.5
```

##### Notes：

- $$s_n^2 = \frac1n \sum^n_{i=1}(y_i - \overline y)^2$$
- $$s^2 = \frac1{n-1} \sum^n_{i=1}(y_i - \overline y)^2$$
- Delta Degrees of Freedom（ddof）



---



#### 大小

##### `max,min,ptp,median`用法与`sum,mean,product`基本相同

``` python
>>> x = np.arange(1,13)
>>> nr.shuffle(x)
>>> x
array([ 4, 11,  5,  1, 10,  8,  6, 12,  9,  2,  7,  3])
>>> np.max(x)
12
>>> np.min(x)
1
>>> np.ptp(x)
11
>>> y = x.reshape((3,4))
>>> y
array([[ 4, 11,  5,  1],
       [10,  8,  6, 12],
       [ 9,  2,  7,  3]])
>>> np.max(y, axis=0)
array([10, 11,  7, 12])
>>> np.max(y, axis=1)
array([11, 12,  9])
```



##### `maximum,minimum`对两个数组，逐元素比较

``` python
>>> x = np.arange(5)
>>> np.maximum(x[None,:], x[:,None])
array([[0, 1, 2, 3, 4],
       [1, 1, 2, 3, 4],
       [2, 2, 2, 3, 4],
       [3, 3, 3, 3, 4],
       [4, 4, 4, 4, 4]])
>>> np.minimum(x[None,:], x[:,None])
array([[0, 0, 0, 0, 0],
       [0, 1, 1, 1, 1],
       [0, 1, 2, 2, 2],
       [0, 1, 2, 3, 3],
       [0, 1, 2, 3, 4]])
```



---



#### 排序

##### 就地改变 vs 重新创建

``` python
>>> x = np.arange(10)
>>> nr.shuffle(x)
>>> x
array([5, 1, 8, 6, 2, 4, 3, 0, 9, 7])
>>> y = np.sort(x)
>>> y
array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
>>> x
array([5, 1, 8, 6, 2, 4, 3, 0, 9, 7])
>>> x.sort()
>>> x
array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
```



##### 排序的轴

``` python
>>> x = np.arange(12)
>>> nr.shuffle(x)
>>> x = x.reshape((3,4))
>>> x
array([[ 4,  5,  7, 10],
       [ 9, 11,  3,  2],
       [ 8,  1,  6,  0]])
>>> np.sort(x)
array([[ 4,  5,  7, 10],
       [ 2,  3,  9, 11],
       [ 0,  1,  6,  8]])
>>> np.sort(x, axis=0)
array([[ 4,  1,  3,  0],
       [ 8,  5,  6,  2],
       [ 9, 11,  7, 10]])
>>> np.sort(x, axis=1)
array([[ 4,  5,  7, 10],
       [ 2,  3,  9, 11],
       [ 0,  1,  6,  8]])
```



---



##### 找到最大或最小的前k个数：`np.partition()`

``` python
In [8]: x = np.arange(1000000)

In [9]: nr.shuffle(x)

In [10]: %timeit np.sort(x)[:5]
63.1 ms ± 75.7 µs per loop (mean ± std. dev. of 7 runs, 10 loops each)

In [11]: %timeit np.partition(x,5)[:5]
6.53 ms ± 63.9 µs per loop (mean ± std. dev. of 7 runs, 100 loops each)
```



##### 注意`np.partition()`的返回形式

``` python
>>> x = np.arange(10)
>>> nr.shuffle(x)
>>> x
array([0, 7, 3, 4, 1, 9, 8, 2, 6, 5])
>>> np.partition(x,5)
array([0, 1, 4, 3, 2, 5, 8, 7, 6, 9])
```



---



##### 百分位数：`np.percentile()`

``` python
>>> r = np.abs(nr.randn(100000))
>>> np.percentile(r, [68.3, 95.4, 99.7])
array([1.00234004, 1.99822207, 2.98253945])
```



---



#### 返回索引

##### `np.argmax()`

``` python
>>> x = np.arange(24)
>>> nr.shuffle(x)
>>> x = x.reshape((2,3,4))
>>> x
array([[[20,  5, 12, 11],
        [17, 10,  4, 16],
        [ 3, 15, 13, 22]],

       [[ 8, 18,  1,  0],
        [21,  6, 14,  9],
        [23, 19,  7,  2]]])
>>> np.argmax(x)
20
>>> np.argmax(x, axis=0)
array([[0, 1, 0, 0],
       [1, 0, 1, 0],
       [1, 1, 0, 0]])
>>> np.argmax(x, axis=1)
array([[0, 2, 2, 2],
       [2, 2, 1, 1]])
>>> np.argmax(x, axis=2)
array([[0, 0, 3],
       [1, 0, 0]])
```



##### `np.argsort()`

``` python
>>> x
array([[[20,  5, 12, 11],
        [17, 10,  4, 16],
        [ 3, 15, 13, 22]],

       [[ 8, 18,  1,  0],
        [21,  6, 14,  9],
        [23, 19,  7,  2]]])
>>> np.argsort(x)
array([[[1, 3, 2, 0],
        [2, 1, 3, 0],
        [0, 2, 1, 3]],

       [[3, 2, 0, 1],
        [1, 3, 2, 0],
        [3, 2, 1, 0]]])
>>> np.argsort(x, axis=0)
array([[[1, 0, 1, 1],
        [0, 1, 0, 1],
        [0, 0, 1, 1]],

       [[0, 1, 0, 0],
        [1, 0, 1, 0],
        [1, 1, 0, 0]]])
>>> np.argsort(x, axis=1)
array([[[2, 0, 1, 0],
        [1, 1, 0, 1],
        [0, 2, 2, 2]],

       [[0, 1, 0, 0],
        [1, 0, 2, 2],
        [2, 2, 1, 1]]])
>>> np.argsort(x, axis=2)
array([[[1, 3, 2, 0],
        [2, 1, 3, 0],
        [0, 2, 1, 3]],

       [[3, 2, 0, 1],
        [1, 3, 2, 0],
        [3, 2, 1, 0]]])
```



##### `np.argpartition()`

``` python
>>> x.flatten()
array([20,  5, 12, 11, 17, 10,  4, 16,  3, 15, 13, 22,  8, 18,  1,  0, 21,
        6, 14,  9, 23, 19,  7,  2])
>>> np.argpartition(x.flatten(), 5)[:5]
array([15, 14, 23,  8,  6])
>>> x.flatten()[np.argpartition(x.flatten(), 5)[:5]]
array([0, 1, 2, 3, 4])
```



---



#### 统计

##### `np.unique()`

``` python
>>> np.unique(nr.randint(0,5,10))
array([0, 1, 2, 3, 4])

>>> a = nr.randint(0,5,10)
>>> x, idx = np.unique(a, return_index=True)
>>> x
array([0, 1, 2, 4])
>>> a[idx]
array([0, 1, 2, 4])
```



##### `np.bincount()`

``` python
>>> a
array([0, 1, 4, 4, 0, 0, 1, 4, 2, 0])
>>> np.bincount(a)
array([4, 2, 1, 0, 3])
```



##### `np.histogram(a, bins=10, range=None, density=False)`

``` python
>>> np.set_printoptions(precision=2)
>>> a = nr.randn(10000)
>>> hist, hist_edge = np.histogram(a)
>>> hist
array([   8,   93,  444, 1553, 2818, 2888, 1630,  489,   72,    5])
>>> hist_edge
array([-4.02, -3.22, -2.42, -1.62, -0.82, -0.02,  0.78,  1.58,  2.38,
        3.18,  3.98])

>>> hist, hist_edge = np.histogram(a, bins=5)
>>> hist
array([ 101, 1997, 5706, 2119,   77])
>>> hist_edge
array([-4.02, -2.42, -0.82,  0.78,  2.38,  3.98])

>>> hist, hist_edge = np.histogram(a, bins=[-10,-1,1,10])
>>> hist
array([1592, 6792, 1616])
>>> hist_edge
array([-10,  -1,   1,  10])

>>> hist, hist_edge = np.histogram(a, bins=5, range=(-1,1))
>>> hist
array([1167, 1455, 1568, 1479, 1123])
>>> hist_edge
array([-1. , -0.6, -0.2,  0.2,  0.6,  1. ])

>>> hist, hist_edge = np.histogram(a, bins=5, range=(-1,1), density=True)
>>> hist
array([0.43, 0.54, 0.58, 0.54, 0.41])
```



---









#### 判断

##### `np.where(condition, y, z)` (y if condition else z)

``` python
>>> x = np.arange(12).reshape((3,4))
>>> x
array([[ 0,  1,  2,  3],
       [ 4,  5,  6,  7],
       [ 8,  9, 10, 11]])
>>> np.where(x >5)
(array([1, 1, 2, 2, 2, 2]), array([2, 3, 0, 1, 2, 3]))
>>> x[np.where(x>5)]
array([ 6,  7,  8,  9, 10, 11])
>>> np.where(x>5, 11-x, x)
array([[0, 1, 2, 3],
       [4, 5, 5, 4],
       [3, 2, 1, 0]])
```

##### Notes：

- condition.shape == y.shape == z.shape



##### 分段函数：`np.piecewise(x, condlist, funclist)`

``` python
>>> x = np.arange(-2,3)
>>> x
array([-2, -1,  0,  1,  2])
>>> np.piecewise(x, [x<0, x>=0], [lambda x:0, lambda x:x])
array([0, 0, 0, 1, 2])
```



---



#### 数组的拼接与换轴

##### `np.concatenate()`

``` python
>>> a = np.arange(6).reshape((2,3))
>>> b = np.arange(6,12).reshape((2,3))
>>> a
array([[0, 1, 2],
       [3, 4, 5]])
>>> b
array([[ 6,  7,  8],
       [ 9, 10, 11]])
>>> np.concatenate((a,b))
array([[ 0,  1,  2],
       [ 3,  4,  5],
       [ 6,  7,  8],
       [ 9, 10, 11]])
>>> np.concatenate((a,b)).shape
(4, 3)
>>> np.concatenate((a,b), axis=1)
array([[ 0,  1,  2,  6,  7,  8],
       [ 3,  4,  5,  9, 10, 11]])
>>> np.concatenate((a,b), axis=1).shape
(2, 6)
```



##### `np.transpose()`

``` python
>>> x = np.arange(24).reshape((2,3,4))
>>> x
array([[[ 0,  1,  2,  3],
        [ 4,  5,  6,  7],
        [ 8,  9, 10, 11]],

       [[12, 13, 14, 15],
        [16, 17, 18, 19],
        [20, 21, 22, 23]]])
>>> x.shape
(2, 3, 4)
>>> np.transpose(x,(1,0,2))
array([[[ 0,  1,  2,  3],
        [12, 13, 14, 15]],

       [[ 4,  5,  6,  7],
        [16, 17, 18, 19]],

       [[ 8,  9, 10, 11],
        [20, 21, 22, 23]]])
>>> np.transpose(x,(1,2,0))
array([[[ 0, 12],
        [ 1, 13],
        [ 2, 14],
        [ 3, 15]],

       [[ 4, 16],
        [ 5, 17],
        [ 6, 18],
        [ 7, 19]],

       [[ 8, 20],
        [ 9, 21],
        [10, 22],
        [11, 23]]])
```

##### Notes：

- 换轴之后，元素的排列的推导，遵循C-order或者F-order



---



#### 结束语：

- 到目前为止，基本上你可能会用到的所有的Numpy函数都在这里了
- 当遇到其他用途的时候，建议使用Scipy，Pandas，Scikit-Learn，h5py等
- 很多容易错，容易晕的地方，都可以追溯到第三节课---ndarray在内存上的分布
- 下节课，我们讲解真正的内功心法：矢量化编程思维







