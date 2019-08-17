### Python核心编程-Numpy篇-第1节课

#### 本节课大纲

- Numpy是什么？
- 为什么要学Numpy？
- Numpy为何如此快？
- 除了快，还有呢？
- 为什么需要听这门课？
- 课程大纲
- 课程学习方法

#### Numpy是什么？

##### 看看维基百科

> support for **large**, **multi-dimensional arrays** and **matrices**, along with a large collection of high-level **mathematical functions to operate on these arrays**. 

##### 为什么不用List？

- List本质上是一个链表，链表有链表的优势，但也有局限性
- List在特定任务上的存储效率，操作效率，计算效率太低

#### 为什么要学Numpy？

- 运算快
- 省内存
- 函数库

##### 能有多快？直接学TensorFlow呗？

在一个线性回归任务中，有人做过测评，得到如下结果：

| Implementation                       | Elapsed Time |
| ------------------------------------ | ------------ |
| Pure Python with list comprehensions | 18.65s       |
| Numpy                                | 0.32s        |
| TensorFlow on CPU                    | 1.20s        |

[Reference: Pure Python vs NumPy vs TensorFlow Performance Comparison](https://realpython.com/numpy-tensorflow-performance/)

##### Numpy与TensorFlow如何抉择？

|          |    TensorFlow    |        Numpy         |
| :------: | :--------------: | :------------------: |
| 框架目标 | Machine Learning | Scientific Computing |
| 运行架构 |  CPU，GPU，TPU   |         CPU          |
| 底层语言 |       C++        |      C、Fortran      |
|  分布式  |       支持       |        不支持        |
| 自动微分 |       支持       |        不支持        |
| 上手难度 |       较难       |         一般         |

---

#### 为什么Numpy可以这么快？

##### 核心数据结构：ndarray

- 内存使用效率高
- 支持快速矢量化运算
- 语言级别的性能优势

##### 关于内存使用效率，这里简单举个例子

``` py
>>> import numpy as np
>>> from sys import getsizeof
>>> py_list = list(range(10000))
>>> np_arr = np.array(py_list)
>>> getsizeof(py_list)
90112
>>> np_arr.nbytes
80000
>>> sum([getsizeof(x) for x in range(10000)])
279996
```



#### 除了快，还有什么理由让你不得不学Numpy？

##### 生态

- scipy
- pandas
- scikit-learn
- matplotlib
- TensorFlow
- PyTorch

#### 为什么需要听这门课？

- 系统：能找到的为数不多的真正系统讲解Numpy的课程
- 梯度：从入门到高手级别，都能找到值得学习的知识点
- 深度：让你看清楚Numpy ndarray在内存上大概是什么样的
- 广度：让你了解Numpy内置的满目琳琅的兵器库
- 思想：从Python的面向对象编程到Numpy的矢量化编程

---

#### 课程大纲

|         课程名称          |       课程简介        |
| :-----------------------: | :-------------------: |
|  第二节课：Numpy快速入门  | 一节课，让你用上Numpy |
| 第三节课：内存上的ndarray | 一节课，让你看透Numpy |
|  第四节课：Numpy高阶编程  | 一节课，让你玩转Numpy |
|  第五节课：Numpy的IO编程  | 一节课，让你打通Numpy |
|  第六节课：Numpy的函数库  | 一节课，让你爱上Numpy |
|  第七节课：Numpy编程思想  | 一节课，让你用好Numpy |

---

#### 课程学习方法

|    人群     |           目标            | 需要学习的课程 |
| :---------: | :-----------------------: | :------------: |
| Numpy零基础 |   能把Numpy顺利使用起来   |    第二节课    |
| Numpy初学者 |   想了解Numpy都能干什么   |    第六节课    |
| Numpy初学者 |   想学习Numpy的高级用法   |    第四节课    |
| Numpy经常用 | 想了解Numpy的底层数据架构 |    第三节课    |
| Numpy经常用 |  想用Numpy跟其他语言交互  |    第五节课    |
| Numpy经常用 |  希望真正发挥Numpy的威力  |    第七节课    |

---

#### 个人建议

- 如果时间来得及，建议从头学到尾
- 认真学完Python核心课的同学们已经反馈说，付出的时间和精力完全没有白费
- 课程上线时间表：预计3月5日以前全部上线，每1-2天更新一集