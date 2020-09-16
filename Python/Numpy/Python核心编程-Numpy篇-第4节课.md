### Python核心编程-Numpy篇-第4节课



#### 本节课的OKR

##### O：

- 深入理解Broadcasting
- 基本掌握Advanced Indexing
- 初步认识nditer
- 初步认识masked array



##### KR：

- 能用Broadcasting的视角解读Numpy代码
- 能用Advanced Indexing处理实际问题
- 需要迭代的时候，能正确使用nditer进行迭代
- 能用masked array清洗数据，或处理复杂逻辑



---



#### Broadcast：处理形状不同的数组的计算机制

- 先比对`ndim`，不一致，则在小的数组上补1升维
- 当`ndim`相同后，在`shape`层逐一比对，要么相同，要么其中一个是1，否则报错
- 如果可以进行Broadcast，则将长度为1的那一轴进行复制，使两个数组`shape`相等
- 最后按照标准ndarray的方式进行计算



##### 0维 + 1维

``` python
>>> a = np.arange(12)
>>> a
array([ 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11])
>>> a.ndim
1
>>> a.shape
(12,)
>>> a + 1
array([ 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12])
```



##### 1维 + 2维

``` python
>>> b = np.arange(12).reshape((1,12))
>>> b.ndim
2
>>> b.shape
(1, 12)
>>> c = a + b
>>> c
array([[ 0,  2,  4,  6,  8, 10, 12, 14, 16, 18, 20, 22]])
>>> c.ndim
2
>>> c.shape
(1, 12)
```



##### 2维 + 2维

``` python
>>> a = np.arange(12)
>>> b = a.reshape((12,1))
>>> c = a.reshape((1,12))
>>> d = b + c
>>> d.ndim
2
>>> d.shape
(12, 12)
>>> d
array([[ 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11],
       [ 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12],
       [ 2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13],
       [ 3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14],
       [ 4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15],
       [ 5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16],
       [ 6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17],
       [ 7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18],
       [ 8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19],
       [ 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20],
       [10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21],
       [11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22]])
```



---



#### 布尔数组索引：高性能数组元素过滤器

``` python
>>> import numpy as np
>>> from numpy import random as nr
>>> a = np.arange(10)
>>> a
array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
>>> nr.shuffle(a)
>>> a
array([1, 8, 4, 9, 6, 7, 2, 5, 0, 3])
>>> a > 5
array([False,  True, False,  True,  True,  True, False, False, False, False])
>>> a[a>5]
array([8, 9, 6, 7])
```

##### Notes：

- `shuffle`函数就地计算，直接修改原始数组，无返回值
- ndarray可以直接与一个常数进行比较，本质上是执行了Broadcast，返回结果数组
- 向ndarray传递一个布尔数组，仅返回True对应的元素



``` python
>>> b = np.arange(24)
>>> nr.shuffle(b)
>>> b
array([ 7, 19, 16, 18, 11,  2,  1, 13,  8,  9,  6, 14,  4, 10, 22, 23, 17,
       21, 20, 15,  0,  5, 12,  3])
>>> b = b.reshape((2,3,4))
>>> b
array([[[ 7, 19, 16, 18],
        [11,  2,  1, 13],
        [ 8,  9,  6, 14]],

       [[ 4, 10, 22, 23],
        [17, 21, 20, 15],
        [ 0,  5, 12,  3]]])
>>> b > 15
array([[[False,  True,  True,  True],
        [False, False, False, False],
        [False, False, False, False]],

       [[False, False,  True,  True],
        [ True,  True,  True, False],
        [False, False, False, False]]])
>>> b[b>15]
array([19, 16, 18, 22, 23, 17, 21, 20])
```

##### Notes：

- `shuffle`函数只在第一个维度上重排，若多维数组仅重排第一轴
- 布尔索引仅返回结果的一维数组，无论原数组是否是多维数组
- 思考：布尔数组返回的一维数组，是View还是Copy？



---



#### 整数数组索引：高性能数组元素选择器

``` python
>>> a
array([1, 8, 4, 9, 6, 7, 2, 5, 0, 3])
>>> np.where(a>5)
(array([1, 3, 4, 5]),)
>>> a[np.where(a>5)]
array([8, 9, 6, 7])

>>> b
array([[[ 7, 19, 16, 18],
        [11,  2,  1, 13],
        [ 8,  9,  6, 14]],

       [[ 4, 10, 22, 23],
        [17, 21, 20, 15],
        [ 0,  5, 12,  3]]])
>>> np.where(b>15)
(array([0, 0, 0, 1, 1, 1, 1, 1]), array([0, 0, 0, 0, 0, 1, 1, 1]), array([1, 2, 3, 2, 3, 0, 1, 2]))
>>> b[np.where(b>15)]
array([19, 16, 18, 22, 23, 17, 21, 20])

>>> len(b[np.where(b>15)]) == len(np.where(b>15)[0])
True
>>> b.ndim == len(np.where(b>15))
True
```

##### Notes：

- `np.where`返回一个由一组等长数组组成的tuple
- 数组的长度代表返回元素的个数
- 数组的个数与判断条件中数组的维度相同



---



#### Numpy式迭代

##### 初见nditer

``` python
>>> a = np.arange(6).reshape((2,3))
>>> a
array([[0, 1, 2],
       [3, 4, 5]])
>>> b = a.T
>>> b
array([[0, 3],
       [1, 4],
       [2, 5]])
>>> [x for x in np.nditer(a)]
[array(0), array(1), array(2), array(3), array(4), array(5)]
>>> [x for x in np.nditer(b)]
[array(0), array(1), array(2), array(3), array(4), array(5)]
```

##### Notes：

- 默认情况下，nditer的迭代基于内存上的结构
- 多维转一维
- 转置由于没有改变内存结构，因此，迭代次序不变



##### 通过改变内存结构，修改迭代次序

``` python
>>> [x for x in np.nditer(a.T.copy(order='C'))]
[array(0), array(3), array(1), array(4), array(2), array(5)]
>>> [x for x in np.nditer(a.copy(order='F'))]
[array(0), array(3), array(1), array(4), array(2), array(5)]
```

##### Notes：

- 强制改变内存结构，可以修改迭代次序



##### 通过修改nditer的参数，直接修改迭代次序

``` python
>>> [x for x in np.nditer(a,order='F')]
[array(0), array(3), array(1), array(4), array(2), array(5)]
```

##### Notes：

- 内存与计算的权衡



##### 迭代过程中，修改原数组的元素的值

``` python
>>> a
array([[0, 1, 2],
       [3, 4, 5]])
>>> with np.nditer(a) as it:
...     for x in it: x = x + 1
...
>>> a
array([[0, 1, 2],
       [3, 4, 5]])
>>> with np.nditer(a) as it:
...     for x in it: x[...] = x + 1
...
Traceback (most recent call last):
  File "<stdin>", line 2, in <module>
ValueError: assignment destination is read-only
>>> with np.nditer(a, op_flags=['readwrite']) as it:
...     for x in it: x[...] = x + 1
...
>>> a
array([[1, 2, 3],
       [4, 5, 6]])
```

##### Notes：

- 回顾：分清Copy和View，如果希望修改原数组，需要通过View的方式
- 默认情况下，nditer的时候，内存是read-only状态
- 通过指定`op_flags=['readwrite']`将内存状态更改为读写模式
- 最佳实践：使用上下文管理器，让危险状态无法蔓延



---



#### Masked Array：处理瑕疵数据的利器

``` python
>>> import numpy.ma as ma
>>> a = np.arange(-5,5)
>>> a
array([-5, -4, -3, -2, -1,  0,  1,  2,  3,  4])
>>> nr.shuffle(a)
>>> a
array([ 0,  2, -4, -5, -3,  1, -1,  3,  4, -2])
>>> b = ma.masked_where(a<0,a)
>>> b
masked_array(data=[0, 2, --, --, --, 1, --, 3, 4, --],
             mask=[False, False,  True,  True,  True, False,  True, False,
                   False,  True],
       fill_value=999999)
>>> b.mean()
2.0
>>> a.mean()
-0.5
>>> b.set_fill_value(0)
>>> b
masked_array(data=[0, 2, --, --, --, 1, --, 3, 4, --],
             mask=[False, False,  True,  True,  True, False,  True, False,
                   False,  True],
       fill_value=0)
>>> b.filled()
array([0, 2, 0, 0, 0, 1, 0, 3, 4, 0])
>>> type(b)
<class 'numpy.ma.core.MaskedArray'>
>>> type(b.filled())
<class 'numpy.ndarray'>
```

##### Notes：

- mask为True的元素被屏蔽
- 在填充替换的时候，用fill_value去替换所有mask为True的元素，并返回ndarray



---



#### 结束语：

- Numpy高级用法还有很多，这里仅粗浅的介绍了比较常用的几个
- 个人不建议把Numpy的高级用法全都学会，把课程中出现的这几个用到极致已经足够了