第三节 Python基础语法

1. 谈谈变量与对象的关系，以及变量在内存中的情况。

　　Python中，定义变量必须由对象赋值，对象类型决定变量类型。从本质上来说，对象是存储数据的实体，而变量是指向对象的指针。举例来说，你的名字和本人就是变量与对象的关系，本人为实体，即对象，而名字只是指向你的一个指针，即变量。（挺别扭=_=）

　　变量无类型，对象有类型。变量类型由对象类型所决定。

2. Python基础的数据类型有哪些？基础的数据结构有哪些？谈谈你对5种基本的数据结构理解（性质，用途，用法）。

　　基础数据类型：整型，浮点型，布尔型，字符串，NULL

　　基础数据结构：list, tuple, dict, set, str

　　list:

　　（1）性质：可变有序集合

　　（2）用途：随机存取

　　（3）用法：切片，索引

　　　　　　　　append(), pop(), + , *,  list[0], list[-1]

　　tuple:

　　（1）性质：不可修改的list

　　（2）用途：一般用于返回多个返回值

　　（3）用法：（）

　　dict:

　　（1）性质：使用hash结构，查找速度快

　　（2）用途：键值对，快速存取

　　（3）用法：

　　　　　　　增：d['*key_not_int_dict*'] = **

　　　　　　　删：d.pop('*key_in_dict*')

　　　　　　　改：d['*key_in_dict*'] = **

　　　　　　　查：'any_key' in d    或者　d.get('key')

　　set:

　　（1）性质：无序，**不可变**，无重复（dict中的key）

　　（2）用途：用于无序数据

　　（3）用法：s.add() , s.remove()



3. 说下引用与拷贝的使用。



　　变量是对象的名称，引用则为对象的别名（小名），改变引用即改变对象。

　　以list为例:

```python
>>> a = [1, 2, 3]
>>> b = a
>>> id(a) == id(b)
 True
>>> b.append(9)
>>> a
 [1, 2, 3, 9]
```



```python
>>> a = [1, 2, 3]
>>> b = a[:]
>>> id(a) == id(b)
 False
>>> b.append(9)
>>> a
 [1, 2, 3]
```



#### 小结

![小结](C:\Users\dream\Desktop\Python快速面面观.png)



































