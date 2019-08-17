### Python核心编程-Numpy篇-第3节课



#### 本节课的目标人群及OKR

##### O：

- 避免由于缺少对ndarray底层的认知而编写bug代码
- 避免由于缺少对ndarray底层的认知而编写低效代码
- 成为Numpy水平前1%的高手



##### KR：

- 清楚ndarray是如何从内存上的一维变成程序里的多维的
- 清楚ndarray对象的大致结构
- 清楚ndarray的内存模型的几个重要细节问题
- 深入理解View的本质



---



#### 课程主要内容

- 从逻辑层面认识ndarray
- 从代码层面认识ndarray
- 从内存层面认识ndarray
- 重新理解ndarray的View与Copy
- 深入理解Indexing Order



---



#### ndarray的本质：

- 内存上一维连续二进制流
- 用于解读二进制流的模型



``` python
>>> a = np.arange(10)
>>> a.data
<memory at 0x10acbd588>
```



---



#### ndarray对象包含的信息：

- 每个数据元素占用多少字节
- 数据流在内存上的起始位置
- 这个数组是几维的？每个维度的大小？
- 两个元素之间的距离（不一定是元素大小的整数倍）
- 每个数据元素是大端还是小端？
- 引用的内存块是否是只读？
- 每个数据元素如何解读？即数据类型
- 数据是C-order还是Fortran-order



``` python
>>> b = np.arange(24).reshape((2,3,4))
>>> b.itemsize
8
>>> b.data
<memory at 0x1061e48b8>
>>> b.ndim
3
>>> b.shape
(2, 3, 4)
>>> b.strides
(96, 32, 8)
>>> b.dtype.byteorder
'='
>>> b.flags
  C_CONTIGUOUS : True
  F_CONTIGUOUS : False
  OWNDATA : False
  WRITEABLE : True
  ALIGNED : True
  WRITEBACKIFCOPY : False
  UPDATEIFCOPY : False
   
>>> b.dtype
dtype('int64')

>>> np.arange(24).flags
  C_CONTIGUOUS : True
  F_CONTIGUOUS : True
  OWNDATA : True
  WRITEABLE : True
  ALIGNED : True
  WRITEBACKIFCOPY : False
  UPDATEIFCOPY : False
    
>>> np.arange(24).reshape((2,3,4)).flags
  C_CONTIGUOUS : True
  F_CONTIGUOUS : False
  OWNDATA : False
  WRITEABLE : True
  ALIGNED : True
  WRITEBACKIFCOPY : False
  UPDATEIFCOPY : False
    
>>> np.arange(24).reshape((2,3,4),order='F').flags
  C_CONTIGUOUS : False
  F_CONTIGUOUS : True
  OWNDATA : False
  WRITEABLE : True
  ALIGNED : True
  WRITEBACKIFCOPY : False
  UPDATEIFCOPY : False
```





---



#### ndarray对象的逻辑组成：

- block of memory：raw data
- Indexing schema：how to locate an element
- Data Type Descriptor：how to interpret an element



---



#### ndarray对象的代码组成：

- dtype对象
- ndim
- shape
- strides
- data指针



---



#### ndarray对象的内存组成：

- metadata
- raw data



---



#### 如何根据ndarray对象解读内存上的二进制流

1. 根据data指针找到ndarray解读的二进制流在内存上的位置
2. 根据strides将二进制流切分成数据块
3. 根据dtype对象将数据块解读成数据元素（数据类型及大小端）



---



#### ndarray设计哲学：让绝大多数的多维数组的操作仅需要改变其metadata部分即可



---



#### 重新理解ndarray的View

- 指向相同的内存（Buffer or Data）
- 拥有不同的解读（metadata）

> View算不算是新的ndarray对象？



---



#### 工程常见问题：什么是大小端？

##### 从计算机数据类型与CPU寄存器的长度说起

- 数据存储的最小单位是：字节（Byte）
- 一个字节是8个二进制位：8bit
- 常见数据类型一般是8bit-64bit不等，也就是1byte-8byte不等
- 常见CPU的寄存器长度有16位，32位不等
- 如果寄存器长度是32位，此时CPU去内存二进制流上框出一个int32数据
- 那么，对于不同的处理器硬件，这32位对应的4个byte的顺序有两种
- 从高到低，从低到高，也就是大小端的区别



``` python
>>> a = np.arange(4).astype('>i4')
>>> b = a.view('>i2')
>>> c = a.view('<i2')
>>> a
array([0, 1, 2, 3], dtype=int32)
>>> b
array([0, 0, 0, 1, 0, 2, 0, 3], dtype=int16)
>>> c
array([  0,   0,   0, 256,   0, 512,   0, 768], dtype=int16)
```



##### 弄明白大小端有什么用？凡涉及数据的IO，务必考虑一下大小端问题



##### ndarray的解决方案

- 改变内存上的字节序：`array.byteswap()`
- 改变解读内存字节序的方式：`array.newbyteorder()`

> 思考：两种方式对程序的性能有何影响？



##### 常见的大小端状况

- Intel 80x86系列：小端
- ARM：默认小端，可切换到大端
- C语言：默认小端（Keil 51C单片机C语言是大端）
- Java：默认大端
- 网络数据：普遍是大端



---



#### 工程常见问题：Indexing Order

##### Convention by User：（m，n）or（x，y）

- Matrix-Oriented（由高维到低维）（Numpy里基本遵循此习惯）
- Image-Oriented（由x到y再到z的地理信息表示习惯）



``` python
>>> np.arange(9).reshape((3,3))
array([[0, 1, 2],
       [3, 4, 5],
       [6, 7, 8]])
```



##### Convention by Language：随着内存上二进制流的移动，不同轴的变动速度是不同的

- C
- Fortran



``` python
>>> a = np.arange(9).reshape((3,3),order='C')
>>> b = np.arange(9).reshape((3,3),order='F')
>>> a.ravel()
array([0, 1, 2, 3, 4, 5, 6, 7, 8])
>>> b.ravel()
array([0, 3, 6, 1, 4, 7, 2, 5, 8])
```



---



#### 结束语：

- 本节课需要消耗的认知负担较重，需要多看几遍，多做实验
- 本节课的价值占整个系列课程中的一半以上，吃透本节课内容大有好处
- 相信未来有一天，在面对Numpy的实际问题时，你会因本节课内容，会心一笑