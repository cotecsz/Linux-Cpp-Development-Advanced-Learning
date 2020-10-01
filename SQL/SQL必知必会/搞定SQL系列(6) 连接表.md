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

## 小结

<img src="https://static001.geekbang.org/resource/image/e4/0d/e473b216f11cfa7696371bfeadba220d.jpg" alt="img" style="zoom:24%;" />

