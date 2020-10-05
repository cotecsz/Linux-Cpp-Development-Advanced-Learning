//
// Created by Yang Shuangzhen on 2020/10/5.
//
#include <stdio.h>
#include <math.h>

class Point
{
    double x;
    double y;
public:
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    double getX()
    {
        return x;
    }

    double getY()
    {
        return y;
    }

    friend double func(Point& p1, Point& p2);
};

double func(Point& p1, Point& p2)
{
    double ret = 0;

    ret = (p2.y - p1.y) * (p2.y - p1.y) +
          (p2.x - p1.x) * (p2.x - p1.x);

    ret = sqrt(ret);

    return ret;
}

int main()
{
    Point p1(1, 2);
    Point p2(10, 20);

    printf("p1(%f, %f)\n", p1.getX(), p1.getY());
    printf("p2(%f, %f)\n", p2.getX(), p2.getY());
    printf("|(p1, p2)| = %f\n", func(p1, p2));


    return 0;
}

