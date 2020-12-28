# 搞定SQL系列1 SQL是如何执行的

## 1 SQL执行流程

### 1.1 Oracle 中 SQL执行过程

<img src="images/image-20200915223249514.png" alt="image-20200915223249514" style="zoom:50%;" />



### 1.2 MySQL中的SQL执行过程

<img src="images/image-20200915223618036.png" alt="image-20200915223618036" style="zoom:50%;" />

MySQL是典型C/S 架构，服务端程序为mysqld。其中SQL层与数据库文件的存储方式无关，SQL层结构：

<img src="images/image-20200915224105762.png" alt="image-20200915224105762" style="zoom:30%;" />

SQL语句在MySQL执行流程：SQL语句 -> 缓存查询 -> 解析器 -> 优化器 -> 执行器

</br>

<img src="https://static001.geekbang.org/resource/image/02/f1/02719a80d54a174dec8672d1f87295f1.jpg" alt="img" style="zoom:24%;" />

