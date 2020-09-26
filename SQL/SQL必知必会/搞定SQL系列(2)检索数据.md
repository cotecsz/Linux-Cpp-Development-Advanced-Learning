# 搞定SQL系列(2) 检索数据

## 2.1 SELECT查询的基本语法

SQL文件：[Github地址](https://github.com/cystanford/sql_heros_data)

1. 查询列

   1. 单个列

   ```sql
   SELECT name FROM heros;
   ```

   ​			b. 多个列

   ```sql
   SELECT name, hp_max, attack_max, defense_max FROM heros;
   ```

   ​			c. 所有列

   ```sql
   SELECT * FROM heros;
   ```

> 生产环境中避免使用 `SELECT *` 

2. 起别名(多表查询，简化名称)

    ```sql
   SELECT name AS n, hp_max AS hm, mp_max AS mm, attack_max AS am, defense_max AS dm FROM heros;
   ```

3. 查询常数：在查询时增加常数列

   ```sql
   SELECT '王者荣耀' as platform, name FROM heros;
   ```

   - 如果是字符串，必须使用 单引号

4. 去除重复行

   ```sql
   SELECT DISTINCT attack_range FROM heros;
   SELECT DISTINCT attack_range , name FROM heros;
   ```

   - DISTINCT 放在所有列名之前
   - DISTINCT对后面的列名组合去重，所以第二条sql会列出所有的数据，因为英雄名称不同。

</br>

## 2.2 排序检索

ORDER BY 子句：

- 排序列名：如果ORDER BY 后有一个或多个列名，会先按照第一个进行排序，再依次对后面的列排序
- 排序顺序
  - ASC：递增排序（默认）
  - DESC：递减排序
- 非选择列排序：可以使用非选择列进行排序
- ORDER BY位置：通常在SELECT语句的最后一条子句

示例1：显示英雄名称和最大生命值，按照最大生命值从高到低排序

```sql
SELECT name, hp_max FROM heros ORDER BY hp_max DESC;
```

示例2: 显示英雄名称及最大生命值，按照第一排序最大法力从低到高，当最大法力相等时按照第二排序进行,即最大生命值从高到低

```sql
SELECT name, max_hp FROM hero ORDER BY mp_max, hp_max DESC
```

约束返回结果的数量：LIMIT

示例1: 返回英雄名称及最大生命值，按照最大生命值从高到低排序，返回5条记录

```sql
SELECT name, hp_max FROM heros ORDER BY hp_max DESC LIMIT 5;
```

#### SELECT 执行顺序

1. 关键字顺序

   ```sql
   SELECT ... FROM ... WHERE ... GROUP BY ... HAVING ... ORDER BY...
   ```

2. SELECT语句执行顺序

   ```sql
   FROM > WHERE > GROUP BY > HAVING > SELECT字段 > DISTINCT > ORDER BY > LIMIT
   ```

示例1 ：

```sql
SELECT DISTINCT player_id, player_name, count(*) as num #顺序5
FROM player JOIN team ON player.team_id = team.team_id #顺序1
WHERE height > 1.80 #顺序2
GROUP BY player.team_id #顺序3
HAVING num > 2 #顺序4
ORDER BY num DESC #顺序6
LIMIT 2 #顺序7
```

- 步骤1：通过CROSS JOIN 求笛卡尔积，得到虚拟表vt 1-1
- 步骤2: 通过ON 筛选，在vt1-1 基础上筛选得到 vt1-2
- 步骤3: 添加外部行，如果使用左连接/右连接/全连接，增加外部行，得到vt 1-3
- 步骤4: WHERE，筛选v1 得到v2
- 步骤5: GROUP 和 HAVING 得到 vt3 和 vt4
- 步骤6: SELECT 和 DISTINCT得到 vt5-1 和vt5-2
- 步骤7: ORDER BY得到vt 6
- 步骤8: LIMIT 得到 vt7

</br>

## 2.3 何时使用`SELECT*` ，如何提升 SELECT 查询效率

指定列名，减少数据表查询的网络传输量。提高效率

1. 避免使用 SELECT *
2. 约束返回结果的数量

</br>

小结：

<img src="https://static001.geekbang.org/resource/image/c8/a8/c88258e72728957b43dc2441d3f381a8.jpg" alt="img" style="zoom:30%;" />

提高查询效率的方式

- 约束返回结果的数量
- 指定筛选条件，进行过滤。





