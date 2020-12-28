### Python核心编程-Numpy篇-第2节课



#### 本节课的目标人群及OKR

##### 目标人群

- 已学完Python核心课程20讲
- 很少使用Numpy或还未曾使用过Numpy



##### O：

- 入门Numpy编程



##### KR：

- 能够直接创建ndarray
- 能够将Python内置对象转化为ndarray
- 了解ndarray的基本组成
- 了解ndarray的基本属性
- 了解ndarray的基本类型
- 理解ndarray的轴
- 能正常使用ndarray的索引与切片
- 理解ndarray的基本数学运算的矢量化
- 了解ndarray的View和Copy
- 能够在数组级别操纵ndarray



---



#### ndarray的创建与基本属性

##### 导入模块并确认版本号

``` python
>>> import numpy as np
>>> np.__version__
'1.16.1'
```



##### 使用构造函数`np.array()`创建ndarray

``` python
>>> a = np.array([1,2,3,4])
>>> b = np.array((1,2,3,4))
>>> c = np.array([[1,2],[3,4]])
>>> d = np.array(range(1,5))
>>> a
array([1, 2, 3, 4])
>>> b
array([1, 2, 3, 4])
>>> c
array([[1, 2],
       [3, 4]])
>>> d
array([1, 2, 3, 4])
```

##### Notes：只要是Python的序列对象或是可迭代对象，都可以通过构造函数创建ndarray



##### 使用内置函数直接创建数组（一）

``` python
>>> np.arange(1,5)
array([1, 2, 3, 4])
>>> np.linspace(1,5,5)
array([1., 2., 3., 4., 5.])
>>> np.linspace(0,1,11)
array([0. , 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1. ])
>>> np.int64(np.logspace(0,10,11,base=2))
array([   1,    2,    4,    8,   16,   32,   64,  128,  256,  512, 1024])
```



##### ndarray的基本属性

``` python
>>> a = np.array(range(5))
>>> a.ndim
1
>>> a.shape
(5,)
>>> a.size
5
>>> a.strides
(8,)
>>> a.dtype
dtype('int64')
>>> a.nbytes
40

>>> b = np.array([range(5),range(1,6)])
>>> b
array([[0, 1, 2, 3, 4],
       [1, 2, 3, 4, 5]])
>>> b.ndim
2
>>> b.shape
(2, 5)
>>> b.size
10
>>> b.strides
(40, 8)
>>> b.nbytes
80

>>> b.T
array([[0, 1],
       [1, 2],
       [2, 3],
       [3, 4],
       [4, 5]])
>>> b.T.shape
(5, 2)
>>> b.T.strides
(8, 40)
```



##### ndarray的基本类型

``` python
>>> b = np.array([range(5),range(5,10)])
>>> b.dtype
dtype('int64')
>>> a = np.array([range(5),range(5,10)], dtype=np.int8)
>>> a.dtype
dtype('int8')
>>> b.astype(np.int8)
array([[0, 1, 2, 3, 4],
       [5, 6, 7, 8, 9]], dtype=int8)
>>> b
array([[0, 1, 2, 3, 4],
       [5, 6, 7, 8, 9]])
>>> b.dtype
dtype('int64')

>>> np.int
np.int(           np.int32(         np.int_(          np.integer(       np.intp(
np.int0(          np.int64(         np.int_asbuffer(  np.interp(
np.int16(         np.int8(          np.intc(          np.intersect1d(
    
>>> np.float
np.float(        np.float16(      np.float64(      np.float_power(
np.float128(     np.float32(      np.float_(       np.floating(
    

```



##### 使用内置函数直接创建数组（二）

``` python
numpy.empty(shape, dtype = float, order = 'C')
numpy.zeros(shape, dtype = float, order = 'C')
numpy.ones(shape, dtype = float, order = 'C')
```

``` python
>>> a = np.empty(10, int)
>>> a
array([0, 1, 2, 3, 4, 1, 2, 3, 4, 5])
>>> a.dtype
dtype('int64')

>>> a = np.empty(2,2,int)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: data type not understood
    
>>> a = np.empty((2,2),int)
>>> a
array([[1, 2],
       [3, 4]])
```

``` python
>>> a = np.zeros((2,2))
>>> a
array([[0., 0.],
       [0., 0.]])

>>> a = np.ones((3,3),int)
>>> a
array([[1, 1, 1],
       [1, 1, 1],
       [1, 1, 1]])
```



---



#### 多维数组的轴与元素访问

##### 多维数组元素访问

``` python
>>> a = np.arange(20,dtype=np.int8)
>>> a
array([ 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16,
       17, 18, 19], dtype=int8)

>>> b = a.reshape((4,5))
>>> b
array([[ 0,  1,  2,  3,  4],
       [ 5,  6,  7,  8,  9],
       [10, 11, 12, 13, 14],
       [15, 16, 17, 18, 19]], dtype=int8)

>>> b[1]
array([5, 6, 7, 8, 9], dtype=int8)
>>> b[1][2]
7
>>> b[1,2]
7

>>> b[1:3]
array([[ 5,  6,  7,  8,  9],
       [10, 11, 12, 13, 14]], dtype=int8)


>>> b[1][1:3]
array([6, 7], dtype=int8)

>>> b[0:3][1:3]
array([[ 5,  6,  7,  8,  9],
       [10, 11, 12, 13, 14]], dtype=int8)

>>> b[0:3,1:3]
array([[ 1,  2],
       [ 6,  7],
       [11, 12]], dtype=int8)

>>> b[...,1:3]
array([[ 1,  2],
       [ 6,  7],
       [11, 12],
       [16, 17]], dtype=int8)

>>> b[1:3,...]
array([[ 5,  6,  7,  8,  9],
       [10, 11, 12, 13, 14]], dtype=int8)
```

##### Notes：多维数组的多维切片有坑，需注意



---



#### 了解ndarray数学运算的矢量化

``` python
In [1]: %timeit [1+2 for x in range(10000)]
332 µs ± 713 ns per loop (mean ± std. dev. of 7 runs, 1000 loops each)

In [2]: a = np.arange(10000)

In [3]: b = np.arange(10000,20000)
    
In [4]: %timeit a+b
5.91 µs ± 17.4 ns per loop (mean ± std. dev. of 7 runs, 100000 loops each)
```



---



#### 了解ndarray的 view & copy

##### 变量的重命名

``` python
>>> a = np.arange(10)
>>> id(a)
4421260272
>>> b = a
>>> id(b)
4421260272
```



##### 变量的切片视图

``` python
>>> a
array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
>>> c = a[1:5]
>>> c
array([1, 2, 3, 4])
>>> c[...] = -1
>>> c
array([-1, -1, -1, -1])
>>> a
array([ 0, -1, -1, -1, -1,  5,  6,  7,  8,  9])
```



##### 数组视图的维数更改，并不会影响原数组的维数

``` python
>>> a = np.arange(10)
>>> d = a.view()
>>> d
array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
>>> id(a)
4598513216
>>> id(d)
4598512896

>>> d = d.reshape((2,5))
>>> d
array([[0, 1, 2, 3, 4],
       [5, 6, 7, 8, 9]])

>>> d[0,1] = -1
>>> d
array([[ 0, -1,  2,  3,  4],
       [ 5,  6,  7,  8,  9]])
>>> a
array([ 0, -1,  2,  3,  4,  5,  6,  7,  8,  9])
```



##### 变量的复制

``` python
>>> a = np.arange(10)
>>> a
array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
>>> e = a.copy()
>>> e = e.reshape((2,5))
>>> e
array([[0, 1, 2, 3, 4],
       [5, 6, 7, 8, 9]])
>>> e[1] = -1
>>> e
array([[ 0,  1,  2,  3,  4],
       [-1, -1, -1, -1, -1]])
>>> a
array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
```



---



#### 数组层面的操作

##### 数组变形

``` python
>>> a
array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
>>> a.shape = 2,5
>>> a
array([[0, 1, 2, 3, 4],
       [5, 6, 7, 8, 9]])
>>> a.shape = 5,-1
>>> a
array([[0, 1],
       [2, 3],
       [4, 5],
       [6, 7],
       [8, 9]])
```



##### 数组迭代

``` python
>>> a = np.arange(6).reshape((2,3))
>>> for arr in a: print(arr)
...
[0 1 2]
[3 4 5]

>>> for x in a.flat: print(x)
...
0
1
2
3
4
5
>>> a.flat
<numpy.flatiter object at 0x7fbbce01e400>
```



##### 数组展开（Copy版 vs View版）

``` python
>>> a = np.arange(10)
>>> b = a.flatten()
>>> c = a.ravel()
>>> a
array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
>>> b
array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
>>> c
array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
>>> b[1] = -1
>>> c[2] = -2
>>> a
array([ 0,  1, -2,  3,  4,  5,  6,  7,  8,  9])
>>> b
array([ 0, -1,  2,  3,  4,  5,  6,  7,  8,  9])
>>> c
array([ 0,  1, -2,  3,  4,  5,  6,  7,  8,  9])
```



##### 数组转置

``` python
>>> a = np.arange(10).reshape((2,5))
>>> a
array([[0, 1, 2, 3, 4],
       [5, 6, 7, 8, 9]])
>>> a.T
array([[0, 5],
       [1, 6],
       [2, 7],
       [3, 8],
       [4, 9]])

>>> a = np.arange(24)
>>> a.shape = 2,3,4
>>> a
array([[[ 0,  1,  2,  3],
        [ 4,  5,  6,  7],
        [ 8,  9, 10, 11]],

       [[12, 13, 14, 15],
        [16, 17, 18, 19],
        [20, 21, 22, 23]]])
>>> a.T
array([[[ 0, 12],
        [ 4, 16],
        [ 8, 20]],

       [[ 1, 13],
        [ 5, 17],
        [ 9, 21]],

       [[ 2, 14],
        [ 6, 18],
        [10, 22]],

       [[ 3, 15],
        [ 7, 19],
        [11, 23]]])
>>> a.T.shape
(4, 3, 2)
```



---



#### 总结

##### 你可能会好奇的一些问题：

- View似乎介于变量ID与物理内存之间，它到底是什么？
- 对于ndarray的轴，似乎还是很晕
- ndarray的变形好快，不像是在内存上紧密排列的



##### 如果你非常好奇以上问题，就继续往后学习吧~

























