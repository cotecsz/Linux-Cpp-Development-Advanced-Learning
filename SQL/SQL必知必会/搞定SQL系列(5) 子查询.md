# 搞定SQL系列(5) 子查询

## 5.1 子查询分类

子查询是一种嵌套的查询方式，可以根据子查询是否执行多次，分为关联子查询和非关联子查询。

- 关联子查询：子查询从数据表中查询了数据结果，数据结果仅执行一次，作为主查询条件进行执行
- 非关联子查询：子查询需要执行多次，即循环的方式，从外部查询开始，每次传入子查询进行查询，再将结果反馈至外部。

示例1 - 非关联子查询：查询最高的球员身高为多少

```sql
SELECT player_name, height FROM player WHERE height = (SELECT MAX(height) FROM player);
```

示例2 - 关联子查询：查询每个球队中大于平均身高的球员，显示球员姓名、身高、以及所在球队ID

```sql
SELECT player_name, height, team_id FROM player AS a WHERE height > (SELECT AVG(height) FROM player AS b WHERE a.team_id = b.team_id);
```

</br>

## 5.2 子查询关键字

EXITS 子查询用于判断条件是否满足。

示例3 - EXIT子查询：查询出过场的球员，并且显示他们的姓名，球员ID和球队ID

```sql
SELECT player_id, team_id, name FROM player WHERE EXITS (SECLECT player_id FROM play_score WHERE player.player_id = player_score.player_id);
```

</br>

IN、ANY、ALL、SOME 集合比较子查询

<img src="/Users/lyj/Library/Application Support/typora-user-images/image-20200927165028536.png" alt="image-20200927165028536" style="zoom:50%;" />

示例4 - IN子查询：查询出过场的球员有哪些

```sql
SELECT player_id, team_id, player_name 
FROM player 
WHERE player_id IN (
  SELECT player_id FROM player_score WHERE player.player_id = player_score.player_id);
```

</br>

IN 与EXISTS 模式

IN 使用 表B 的索引

```sql
SELECT * FROM A WHERE cc IN (SELECT CC FROM B);
```

EXISTS使用 表A的索引

```sql
SELECT * FRMO A WHERE EXIST (SELECT CC FROM B WHERE B.cc = A.CC)
```

效率比较：在cc列建立索引情况下，需要比较表A和表B的大小。

- 如果表A比表B大，那么IN子查询效率比EXIST子查询效率高，因为表B如果对cc列进行了索引，所以IN子查询的效率高。
- 如果表A比表B小，使用EXIST子查询效率更高，因为可以使用到A表中对cc列的索引，而不用从B中进行cc列的查询

> 索引是个前提，其实和选择与否 还是要看表的大小。选择的标准，你可以理解为： 小表驱动大表。这种方式下效率是最高的。比如
> SELECT * FROM A WHERE cc IN (SELECT cc FROM B)
> SELECT * FROM A WHERE EXIST (SELECT cc FROM B WHERE B.cc=A.cc)
> 当A小于B时，用EXIST。因为EXIST的实现，相当于外表循环，实现的逻辑类似于：
> for i in A
>   	for j in B
>     		if j.cc == i.cc then ...
>
> 当B小于A时，用IN，因为实现的逻辑类似于：
> for i in B
>   	for j in A
>     		if j.cc == i.cc then ...
> 所以哪个表小就用哪个表来驱动，A表小 就用EXIST，B表小 就用IN

示例5 - ANY 子查询：查询球员表中，比印第安步行者（team_id = 1002) 中任意一个球员的身高高的球员信息，输出球员ID、姓名和身高。

```sql
SELECT player_id, player_name, height FROM player WHERE height > ANY(SELECT height FROM player WHERE team_id = 1002);
```

示例6 - ALL子查询

查询球员表中，比印第安步行者（team_id = 1002) 中所有球员的身高高的球员信息，输出球员ID、姓名和身高。

```sql
SELECT player_id, player_name, height FROM player WHERE height > ALL(SELECT height FROM player WHERE team_id = 1002);
```

</br>

## 5.3 使用子查询作为计算字段

示例7 - 子查询作为计算字段：查询每个球队的队员数

```sql
SELECT team_name, (SELECT COUNT(*) FROM player WHERE player.team_id = team.team_id) AS player_num FROM team;
```



## 5.4 小结

<img src="https://static001.geekbang.org/resource/image/67/48/67dffabba0619fa4d311929c5d1c0f48.png" alt="img" style="zoom:50%;" />











