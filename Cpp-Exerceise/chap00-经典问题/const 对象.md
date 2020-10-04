# const 对象

## 1 const 对象

- const 修饰的对象为只读对象
- 只读对象是编译阶段的概念，运行时无效

</br>

## 2 const 成员函数

const 成员函数的定义：

```C++
Type ClassName::function(Type p) const
```

- const 对象只能调用const 成员函数
- const 成员函数只能调用const 成员函数
- const 成员函数不能改写成员变量的值

实验 const成员函数

```C++
#include <stdio.h>

class Test
{
    int mi;
public:
  	int m_j;
    Test(int i);
    Test(const Test& t);
    int getMi();
};

Test::Test(int i)
{
    mi = i;
}

Test::Test(const Test& t)
{
    
}
    
int Test::getMi()
{
    return mi;
}

int main()
{
    const Test t(1);
    t.mj = 1000;			// error, const 变量只读
  
  	t.getMi(); 				// error, const 对象只能调用const 成员函数，需要将getMi() 声明为const 成员函数
    return 0;
}

```

