//
// Created by Yang Shuangzhen on 2020/9/26.
//

#include <stdio.h>

struct Biology
{
    bool living;
};

struct Animal : Biology
{
    bool movable;

    void findFood()
    {
    }
};

struct Plant : Biology
{
    bool growable;
};

struct Beast : Animal
{
    void sleep()
    {
    }
};

struct Human : Animal
{
    void sleep()
    {
        printf("I'm sleeping...\n");
    }

    void work()
    {
        printf("I'm working...\n");
    }
};

struct Girl : Human
{
private:
    int age;
    int weight;
public:
    void print()
    {
        age = 22;
        weight = 48;

        printf("I'm a girl, I'm %d years old.\n", age);
        printf("My weight is %d kg.\n", weight);
    }
};

struct Boy : Human{
private:
    int height;
    int salary;
public:
    int age;
    int weight;

    void print(){
        height = 175;
        salary = 9000;

        printf("I'm a boy, my height is %d cm.\n", height);
        printf("My salary is %d RMB.\n", salary);
    }
};

int main(){
    Girl g;
    Boy b;

    g.print();

    b.age = 19;
    b.weight = 120;
    //b.height = 180;

    b.print();

    return 0;
}
