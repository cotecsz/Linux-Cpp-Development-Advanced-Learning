# 搞定SQL系列(6) 连接表

## 6.1 连接表的种类

### 6.1.1 笛卡尔积

笛卡尔积是一个数学运算。假设集合X和Y，其笛卡尔积是X与Y的所有组合。

示例1 - 表的笛卡尔积：两种表的笛卡尔积

```sql
SELECT * FROM player, team;
```

</br>

### 6.1.2 等值连接

等值连接是将两张表中都存在的列进行连接。

示例2 - 等值连接 ：将palyer 和team 表中的team_id 用等值连接进行查询

```sql
SELECT player_id, player.team_id, player_name, height, team_name FROM player, team WHERE palyer.team_id = team.team_id;
```

示例3 - 别名使用 ：与示例2相同

```sql
SELECT player_id, a.team_id, player_name, height, team_name FROM player AS a, team AS b WHERE a.team_id = b.team_id;
```

</br>

### 6.1.3 非等值连接

与等值连接相反，使用其他运算符连接的就是非等值连接。

示例4 - 非等值连接：查询每个球员的身高的级别

```sql
SELECT p.player_name, p.height, h.height_level 
FROM player AS p, height_grades AS h
WHERE p.height BETWEEN h.height_lowest AND h.height_highest;
```

</br>

### 6.1.4 外连接

- 左外连接：左边为主表，显示左表中所有行

示例5 - 左外连接：

```sql
SELECT * FROM player LEFT JOIN team ON player.team_id = team.team_id;
```

- 右外连接：右边为主表，显示右表的所有行

示例6 - 右外连接

```sql
SELECT * FROM player RIGHT JOIN team ON player.team_id = team.team_id;
```

</br>

### 6.1.5 自连接

自连接可以对多个表进行操作，也可以对同一个表进行操作。

示例7 - 自连接：查看比布雷尔 格里芬高队员，以及他们对影身高

```sql
SELECT b.player_name, b.height FROM player as a, player as b WHERE a. player_name = '布雷克-格里芬' and a.height < b.height;
```

</br>

## 6.2 SQL 99 标准

### 6.2.1 交叉连接

示例1 - 交叉连接：player 与 team的笛卡尔积结果

```sql
SELECT * FROM player CROSS JOIN team;
```

示例2 - 多张表的交叉连接：

```sql
SELECT * FROM t1 CROSS JOIN t2 CROSS JOIN t3;
```

</br>

### 6.2.2 自然连接 / 等值连接

示例3 - 等值连接：player 与team的等值连接

```sql
SELECT player_id, team_id, player_name, height, team_name FROM player NATURAL JOIN team;
```

在SQL99中使用 `NATURAL JOIN` 代替了 `WHERE player.team_id = team.team_id` 。

</br>

### 6.3.3 ON 指定连接条件

示例4 - 等值连接/ 自然连接的条件指定：

```sql
SELECT player_id, team_id, player_name, height, team_name FROM player NATURAL JOIN team WHERE player.team_id = team.team_id;
```

示例5 - 非等值连接的条件指定：查询球员的身高等级，是哟哦那个palyer和height_grades两张表

```sql
SQL99:
SELECT p.player_name, p.height, h.height_level 
FROM player as p JOIN height_grades as h
ON height BETWEEN h.height_lowest AND h.height_highest;
```

</br>

### 6.3.4 USING 连接

USING指定数据表中的同名字段进行等值连接

示例6 - USING 连接：与示例4等价。

```sql
SELECT player_id, team_id, player_name, height, team_name FROM player JOIN team USING(team_id)
```

</br>

### 6.3.5 外连接

示例7 - 左外连接：

```sql
SELECT * FROM player LEFT JOIN team ON player.team_id = team.team_id;
```

示例8 - 右外连接：

```sql
SELECT * FROM player RIGHT JOIN team ON player.team_id = team.team_id
```

示例9 - 全外连接 = 左右表匹配的数据 + 左表没有匹配的数据 + 右表没有匹配的数据

```sql
SELECT * FROM player FULL JOIN team ON player.team_id = team.team_id
```

</br>

### 6.3.6 自连接

示例10 - 自连接

```sql
SELECT b.player_name, b.height 
FROM player as a JOIN player as b 
ON a.player_name = '布雷克-格里芬' and a.height < b.height;
```

## 小结

1. 内连接：将多个表中满足连接条件的数据查询出来，包括等值连接、非等值连接和自连接。
2. 外连接：返回一个表中所有记录，以及另一个表中所有匹配的行，包括左外连接和右外连接和全连接
3. 交叉连接：即笛卡尔积。返回左表中的每一行与右表中每个行的组合。



<img src="https://static001.geekbang.org/resource/image/e4/0d/e473b216f11cfa7696371bfeadba220d.jpg" alt="img" style="zoom:24%;" />

<img src="https://static001.geekbang.org/resource/image/44/5b/443181aea770ba5844efac6b02e02c5b.jpg" alt="img" style="zoom:24%;" />

