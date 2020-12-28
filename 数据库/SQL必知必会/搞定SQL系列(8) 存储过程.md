# 搞定SQL系列(8) 存储过程

## 8.1 存储过程

### 8.1.1 定义、删除、更新

存储过程是SQL语句的封装，创建存储过程后，可以像使用函数一样调用存储过程。

存储过程定义：

```sql
CREATE PROCEDURE 存储过程名称([参数列表])
BEGIN
		执行语句
END		
```

删除存储过程

```sql
DROP PROCEDURE [存储过程名称]
```

更新存储过程

```sql
ALTER PROCEDURE
```

示例1 - 存储过程：累加计算，计算 1+2+...+n

```sql
DELIMITER //
CREATE PROCEDURE `add_num` (IN n INT)
BEGIN
		DECLARE i INT;
		DECLARE sum INT;
		
		SET i = 1;
		SET sum = 0;
		WHILE i <= n DO
				SET sum = sum + i;
				SET i = i + 1;
		END WHILE
		SELECT sum;
END // 
DELIMITER ;
```

</br>

### 8.1.2 参数列表

<img src="images/image-20201005162519814.png" alt="image-20201005162519814" style="zoom:50%;" />

示例2 - 参数：输出某一类型英雄的最大的最大生命值，最小的最大魔法值，以及平均最大攻击值。

```sql
CREATE PROCEDURE `get_hero_scores` (
			 OUT max_max_hp FLOAT;
  		 OUT min_max_mp FLOAT;
  		 OUT avg_max_attack FLOAT;
  		 s VARCHAR(255)
)
BEGIN
		SELECT MAX(hp_max), MIN(mp_max), AVG(attack_max) FROM heros WHERE role_main=s INTO max_max_hp, min_max_mp, ag_max_attack;
END
```

示例3 - 调用存储过程

```sql
CALL get_hero_scores(@max_max_hp, @min_max_mp, @avg_max_attack, '战士');
SELECT @max_max_hp, @min_max_mp, @avg_max_attack;
```

</br>

## 8.2 流程控制语句

- `BEGIN...END` ：包含多个语句，每个语句以 `;` 结束
- `DECLARE`  ：声明变量
- `SET` ：赋值语句
- `SELECT...INTO` ：变量赋值
- `IF...THEN...ENDIF` ：条件判断
- `CASE` ：多条件分支判断
- `LOOP` 、`LEAVE` 、`ITERATE` ：循环、跳出循环、进入下一次循环
- `REPEAT ... UNTIL... END REPEAT` ：循环语句
- `WHILE...DO... END WHILE` ：循环语句

</br>

## 8.3 小结

<img src="https://static001.geekbang.org/resource/image/54/9f/54a0d3b0c0e5336c1da6fc84c909a49f.jpg" alt="img" style="zoom:24%;" />











