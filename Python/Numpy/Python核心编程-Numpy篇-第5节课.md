### Python核心编程-Numpy篇-第5节课



#### 本节课的OKR

##### O：

- 加深对dtype的理解
- 深入理解结构数组
- 掌握常用的Numpy的磁盘IO操作
- 掌握常用的Numpy的内存IO操作



##### KR：

- 可自如的使用Structured Arrays
- 面对涉及IO的问题，能马上想到Numpy中对应的函数或方式



---



#### Structured Arrays

``` python
>>> sa_a = np.array([('Tom', 20, 65.1), ('Jack', 25, 81.2)], 
                    dtype=[('name','U10'), ('age', 'i2'), ('weight', 'f4')])
>>> sa_a[0]
('Tom', 20, 65.1)
>>> sa_a[1]
('Jack', 25, 81.2)
>>> sa_a.dtype
dtype([('name', '<U10'), ('age', '<i2'), ('weight', '<f4')])
>>> sa_a.strides
(46,)
>>> sa_a.dtype[0]
dtype('<U10')
>>> sa_a.dtype.names
('name', 'age', 'weight')
>>> sa_a['name']
array(['Tom', 'Jack'], dtype='<U10')
>>> sa_a['age']
array([20, 25], dtype=int16)
>>> sa_a['weight']
array([65.1, 81.2], dtype=float32)
```



##### Structured Datatype Creation

- list of tuples: `(fieldname, datatype, shape)`

``` python
>>> np.dtype([('x', 'f4'), ('y', np.float64), ('z', 'i4', (2,2))])
dtype([('x', '<f4'), ('y', '<f8'), ('z', '<i4', (2, 2))])
>>> np.dtype([('x', 'f4'), ('', np.float64), ('z', 'i4', (2,2))])
dtype([('x', '<f4'), ('f1', '<f8'), ('z', '<i4', (2, 2))])
>>> np.dtype([('x', 'f4'), ('', np.float64), ('', 'i4', (2,2))])
dtype([('x', '<f4'), ('f1', '<f8'), ('f2', '<i4', (2, 2))])
```

- A string of comma-separated dtype specifications

``` python
>>> np.dtype('3int8, float32, (2,3)float64, i4')
dtype([('f0', 'i1', (3,)), ('f1', '<f4'), ('f2', '<f8', (2, 3)), ('f3', '<i4')])
```



##### Indexing and Assignment to Structured Arrays

``` python
>>> x = np.array([(0,1,2),(3,4,5)],dtype='i2,f4,i8')
>>> x
array([(0, 1., 2), (3, 4., 5)],
      dtype=[('f0', '<i2'), ('f1', '<f4'), ('f2', '<i8')])

>>> x = np.array(np.arange(6).reshape((2,3)),dtype='i2,f4,i8')
>>> x
array([[(0, 0., 0), (1, 1., 1), (2, 2., 2)],
       [(3, 3., 3), (4, 4., 4), (5, 5., 5)]],
      dtype=[('f0', '<i2'), ('f1', '<f4'), ('f2', '<i8')])

>>> x = np.array([(1,2),(3,4)], dtype=[('foo', 'i8'), ('bar', 'f4')])
>>> x
array([(1, 2.), (3, 4.)], dtype=[('foo', '<i8'), ('bar', '<f4')])
>>> x['foo']
array([1, 3])
>>> x['bar']
array([2., 4.], dtype=float32)
>>> y = x['foo']
>>> y[...] = 0
>>> x
array([(0, 2.), (0, 4.)], dtype=[('foo', '<i8'), ('bar', '<f4')])
>>> y.strides
(12,)
```





---



#### Numpy IO

##### 导出单个ndarray为Numpy二进制文件

``` python
>>> np.save('/tmp/a', np.arange(24).reshape((2,3,4)))
>>> a = np.load('/tmp/a.npy')
>>> a
array([[[ 0,  1,  2,  3],
        [ 4,  5,  6,  7],
        [ 8,  9, 10, 11]],

       [[12, 13, 14, 15],
        [16, 17, 18, 19],
        [20, 21, 22, 23]]])
```

##### Notes：注意命名方式，若无扩展名，Python会自动添加后缀



---



##### 导出多个ndarray为Numpy二进制文件

``` python
>>> a = np.arange(12)
>>> b = np.arange(12).reshape((3,4))
>>> np.savez('/tmp/data', a=a, b=b)
>>> data = np.load('/tmp/data.npz')
>>> data['a']
array([ 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11])
>>> data['b']
array([[ 0,  1,  2,  3],
       [ 4,  5,  6,  7],
       [ 8,  9, 10, 11]])
```

##### Notes：批量导出，每个变量与文件的句柄是key-value形式



---



##### 导出多个ndarray为Numpy二进制文件并压缩

``` python
>>> np.savez_compressed('/tmp/data_compressed', a=a, b=b)
```

##### Notes：

- `data.npz`：642字节
- `data_compressed.npz`：395字节



---



##### 从字符串中加载一维数组

``` python
>>> np.fromstring('1 2', dtype=int, sep=' ')
array([1, 2])
>>> np.fromstring('1, 2', dtype=int, sep=',')
array([1, 2])
```



---



##### 从字符串中加载ndarray

``` python
>>> from io import StringIO
>>> str_a = StringIO(u"0 1\n2 3\n4 5")
>>> a = np.loadtxt(str_a).astype(np.int64)
>>> a
array([[0, 1],
       [2, 3],
       [4, 5]])

>>> d = StringIO(u"M 21 72\nF 35 58")
>>> dt = {'names': ('gender', 'age', 'weight'),'formats': ('S1', 'i4', 'f4')}
>>> x = np.loadtxt(d,dt)
>>> x
array([(b'M', 21, 72.), (b'F', 35, 58.)],
      dtype=[('gender', 'S1'), ('age', '<i4'), ('weight', '<f4')])
```



---













##### 从字符串中通过正则表达式加载ndarray

``` python
>>> with open('test.dat', 'w') as f: 
    f.write("1949 abc\n1979 def\n1999  opq\n2019 xyz")
>>> regexp = r"(\d+)\s+(.+)"
>>> x = np.fromregex('test.dat', regexp, [("num", 'i8'), ("str", 'S3')])
>>> x
array([(1949, b'abc'), (1979, b'def'), (1999, b'opq'), (2019, b'xyz')],
      dtype=[('num', '<i8'), ('str', 'S3')])

```



---



##### Array的格式化字符输出

``` python
>>> x  = np.arange(3.)
>>> np.array2string(x, formatter={'float_kind':lambda x: "%.2f" % x})
'[0.00 1.00 2.00]'
```



---



##### 将Array转化为List

``` python
>>> a = np.arange(6)
>>> a
array([0, 1, 2, 3, 4, 5])
>>> list(a)
[0, 1, 2, 3, 4, 5]
>>> a.tolist()
[0, 1, 2, 3, 4, 5]

>>> b = np.arange(6).reshape((2,3))
>>> b
array([[0, 1, 2],
       [3, 4, 5]])
>>> list(b)
[array([0, 1, 2]), array([3, 4, 5])]
>>> b.tolist()
[[0, 1, 2], [3, 4, 5]]
```



---



##### 从内存中读取一维数组（注意大小端）

``` python
>>> dt = np.dtype(int)
>>> dt = dt.newbyteorder('>')
>>> np.frombuffer(buf, dtype=dt)

>>> s = 'hello world'
>>> np.frombuffer(s, dtype='S1', count=5, offset=6)
array(['w', 'o', 'r', 'l', 'd'],
      dtype='|S1')

>>> np.frombuffer(b'\x01\x02', dtype=np.uint8)
array([1, 2], dtype=uint8)
>>> np.frombuffer(b'\x01\x02\x03\x04\x05', dtype=np.uint8, count=3)
array([1, 2, 3], dtype=uint8)
```



---



##### 从迭代器中读取一维数组

``` python
>>> iterable = (x*x for x in range(5))
>>> np.fromiter(iterable, float)
array([  0.,   1.,   4.,   9.,  16.])
```



---



#### 结束语：

- `np.memmap` vs HDF5(h5py)
- 理解了ndarray内存结构，掌握了ndarray的IO，学会了ndarray的高级用法
- 基本功部分已经告一段落，第六讲是各种招式，第七讲是内功心法