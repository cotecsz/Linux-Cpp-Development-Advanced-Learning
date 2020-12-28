# 搞定SQL系列(10) 游标

## 10.1 什么是游标

游标提供一种灵活的操作方式，使得SQL有面向过程开发的能力。其相当于C语言中的指针，可以指向存储在数据库表中的数据行指针。

## 10.2 如何使用游标

1. 定义游标

```sql
DECLARE cursor_name CURSOR FOR select_statement;
```

2. 打开游标

```sql
OPEN cursor_name;
```

3. 从游标中获取数据

```sql
FETCH cursor_name INTO var_name ...;
```

4. 关闭游标

```sql
CLOSE cursor_name;
```

5. 释放游标

```sql
DEALLOCATE cursor_namec;
```



## 10.3 小结

<img src="https://static001.geekbang.org/resource/image/dc/11/dca1fadf6625b9699c25104e74fb8d11.jpg" alt="img" style="zoom:24%;" />

