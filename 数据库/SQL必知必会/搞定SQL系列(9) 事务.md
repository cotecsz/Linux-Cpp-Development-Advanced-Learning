# 搞定SQL系列(9) 事务

## 9.1 事务特性：ACID

事务的特性：要么完全执行，要么不执行。

1. 原子性（Atomicity， A）：数据处理操作的基本单位
2. 一致性（Consistency，c）：数据库进行事务操作后，由一种一致状态变成另一种一致状态。
3. 隔离性（Isolation，I）：每个事务彼此独立
4. 持久性（Durability，D）：事务提交后对事务的修改是持久性的。

一致性：由具体的业务定义，任何写入数据库的数据都需要满足事先定义的约束规则。

持久性：通过事务日志保证，包括回滚日志和重做日志。

## 9.2 事务控制指令

- `START TRANSACTION` / `BEGIN` ：显式开启一个事务
- `COMMIT` ：提交事务，一旦提交，对数据库的修改是永久性的
- `ROLLBACK`  / `ROLLBACK TO [SAVEPOINT]` ：回滚事务。撤销正在进行的所有没有提交的修改，或者将事务回滚到某个保存点
- `SAVEPOINT` ：在事务中创建保存点，方便后续针对保存点进行回滚。
- `RELEASE SAVEPOINT` ：删除某个保存点
- `SET TRANSACTION` ：设置事务的隔离级别

</br>

## 9.3 事务隔离

事务隔离是事务的基本特性之一，防止数据库在并发处理时出现数据不一致的情况。

示例1 - 查看事务隔离级别

```sql
SHOW VARIABLES LIKE 'transaction_isolation';
```

</br>

### 9.3.1 事务并发处理的异常

事务并发处理时会发生以下异常：脏读、不可重复读、幻读。

#### 脏读

脏读（Dirty Read）：在并发访问数据库时，当一方对数据修改后，但未commit，而有另一方对数据库进行读取，会读取脏数据，称为脏读。

示例2 - 设置事务隔离级别为`读未提交`

```sql
SET SESSION TRANSACTION ISOLATION LEVEL READ UNCOMMITTED;
```

示例3 - 设置取消自动commit

```sql
SET autocommit = 0;
```

示例4 - 模拟脏读：客户端1

```sql
-- ----------------------------
-- Table structure for heros_temp
-- ----------------------------
DROP TABLE IF EXISTS `heros_temp`;
CREATE TABLE `heros_temp`  (
  `id` int(11) NOT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of heros_temp
-- ----------------------------
INSERT INTO `heros_temp` VALUES (1, '张飞');
INSERT INTO `heros_temp` VALUES (2, '关羽');
INSERT INTO `heros_temp` VALUES (3, '刘备');
```

示例4 - 客户端2

```sql 
INSERT INTO heros_temp values(4, '吕布');
```

示例4 - 客户端1

```sql
SELECT * FROM heros_temp;
```



#### 不可重复读

不可重复读（Norepeatable Read)：同一条记录，两次读取结果不一样。

![img](https://static001.geekbang.org/resource/image/c3/b8/c3361eaa98016638fc47af65ce12edb8.png)

示例5 - 模拟不可重复读：客户端1

```sql
SELECT name FROM heros_temp WHERE id = 1;
```

客户端2 

```sql
BEGIN;
UPDATE heros_temp SET name = '张翼德' where id = 1;
```

客户端1

```sql
SELECT name FROM heros_temp WHERE id = 1;
```

#### 幻读

幻读(Phantom Read)：事务A根据条件查询得到N条数据，事务B此时又更改或者增加了M条符合事务A查询的数据，当A再次查询时，会发现有N+M条数据，产生幻读。

示例6 - 幻读：客户端1

```sql
SELECT * FROM heros_temp;
```

客户端2

```sql
BEGIN;
INSERT INTO heros_temp values(4, '吕布');
```

客户端1

```sql
SELECT * FROM heros_temp;
```



</br>

### 9.3.2 事务隔离级别

解决异常数量从少到多的顺序决定隔离级别，隔离级别从高低到高分别是

- 读未提交（READ UNCOMMITTED)
- 读已提交 (READ COMMITTED)
- 可重复读 (REPEATABLE READ)
- 可串行化 (SERIALIZABLE)

![img](https://static001.geekbang.org/resource/image/b0/95/b07103c5f5486aec5e2daf1dacfd6f95.png)

#### 读未提交

读未提交是指允许读到未提交的数据，这种查询不使用锁，可能会产生脏读、不可重复读、幻读等情况。

#### 读已提交

读已提交是指只能读取已经commit 的数据，所以可以避免读取脏数据。如果要避免不可重复读或者幻读，需要编写带加锁的SQL语句。

#### 可重复读

可重复读保证一个事务在相同查询条件下两次查询条件得到的数据结果是一致的。可以避免不可重复读和脏读，但无法避免幻读。

#### 可串行化

可串行化指将事务进行串行化，即在一个队列中按照顺序执行，是最高的隔离等级。可以解决所有可能出现的异常情况，但牺牲了系统的并发性。



### 9.3.3 小结

<img src="https://static001.geekbang.org/resource/image/aa/fb/aa2ae6682a571676b686509623a2a7fb.jpg" alt="img" style="zoom:50%;" />



> 不可重复读 VS 幻读的区别：
> 不可重复读是同一条记录的内容被修改了，重点在于UPDATE或DELETE
> 幻读是查询某一个范围的数据行变多了或者少了，重点在于INSERT

> 脏读：一个事务读取了另一个事务改写但还未提交的数据。
> 		幻读：一个事务读取了另一个事务插入的新纪录。
> 		不可重复读：在同一个事务中，多次读取同一数据返回的结果有所不同。

> 读未提交：在这个隔离级别下，事务A会读到事务B未提交的数据，在事务B回滚后，事务A读到的数据无意义，是脏数据，称为 脏读
>         读已提交：在这个隔离级别下，只有在事务B已提交时，事务A才能读到，如果事务A先查询id为1的记录，之后事务B修改这条记录并提交，事务A再读取，两次结果会不一致，所以不可重复读。
>         可重复读：在这个隔离级别下，就算事务B的修改已经提交，事务A读到的数据依旧是一致的。当事务B插入一条新数据并提交之后，事务A查询不到当前数据，查询不到就以为不存在，但是事务A却可以更新这条数据成功，并且更新后再次查询，数据出现了。一开始查询不到，但能修改，再次查询又出现了，跟幻觉一样，所以称为　幻读。







