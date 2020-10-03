# 搞定SQL系列(7) 视图

## 7.1 视图及SQL操作

视图本质为虚拟表，本身是没有数据的，其可以看作是

- 一张表或多张表的数据结果集
- SELECT 语句的封装

在大型项目中，视图可以提升效率。

### 7.1.1 创建视图

创建视图语法：

```sql
CREATE VIEW view_name AS 	// 视图名
SELECT column1, column2		// 列名
FROM table
WHERE condition;					// 过滤条件
```

示例1 - 创建视图：查询比NBA球员的平均身高 高的球员，显示球员ID和身高。

```sql
CREATE VIEW player_above_avg_height AS 
SELECT player_id, height
FROM player
WHERE height > (SELECT AVG(height) from player);
```

示例2 - 使用视图：

```sql
SELECT * FROM player_above_avg_hegiht;
```

### 7.1.2 嵌套视图

示例3 - 嵌套视图：找到比上个表的球员平均身高 高的球员作为新的视图

```sql
CREATE VIEW player_above_above_avg_height AS 
SELECT player_id, height
FROM player_above_avg_height 
WHERE height > (SELECT AVG(height) FROM player_above_avg_height);
```

</br>

### 7.1.3 修改视图

修改视图语法：更新原有视图

```sql
ALERT VIEW view_name AS
SELECT column1, column2
FROM table
WHERE condition;
```

示例4 - 修改视图：增加字段 player_name

```sql
ALERT VIEW player_above_avg_height AS
SELECT player_id, player_name, height
FROM player
WHERE height > (SELECT AVG(height) FROM player);
```

</br>

### 7.1.3 删除视图

删除视图语法：

```sql
DROP VIEW view_name;
```

示例5 - 删除视图：删除创建的视图

```sql
DROP VIEW player_above_avg_height;
```

</br>

## 7.2 使用视图简化SQL操作

### 7.2.1 利用视图完成复杂的连接

示例6 - 利用视图完成复杂的连接：对player和height_grades表进行连接

```sql
CREATE VIEW player_height_grades AS 
SELECT p.player_name, p.height, h.height_level
FROM player as p JOIN height_grades as h
ON height BETWEEN h.height_lowest AND h.height_highest;
```

```sql
SELECT * FROM player_height_grades WHERE height >= 1.90 AND height <= 2.08;
```

</br>

### 7.2.2 利用视图对数据进行格式化 

示例7 - 利用视图对数据进行格式化 ：输出球员姓名和对应球队，对应格式为player_name(team_name)

```sql
CREATE VIEW player_team AS
SELECT CONCAT(player_name, '()', team.team_name, ')') AS player_name FROM player JOIN team WHERE player.team_id = team.team_id;
```

```sql
SELECT * FROM player_team;
```

</br>

### 7.2.3 使用视图与计算字段

示例8 - 计算字段：统计每位球员在煤厂比赛中的二分球、三分球和发球的得分，通过创建视图完成

```sql
CREATE VIEW game_player_score AS
SELECT 
		game_id, player_id, 
    (shoot_hits-shoot_3_hits)*2 AS shoot_2_points,
    shoot_3_hits*3 AS shoot_3_points, 
    shoot_p_hits AS shoot_p_points, score  
FROM player_score
```

```sql
SELECT * FROM game_player_score;
```

</br>

## 7.3 视图 V.S. 临时表

临时表是真实存在的数据表，不用于长期存放数据，只为当前连接存在，关闭连接后会自动释放。

视图本身是不存储数据，通常视图仅仅用于查询。



## 7.4 小结

<img src="https://static001.geekbang.org/resource/image/8a/30/8afa99e7d1ac1de2c802cf0c61004b30.jpg" alt="img" style="zoom:24%;" />





