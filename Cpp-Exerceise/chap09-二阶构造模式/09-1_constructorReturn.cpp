//
// Created by Yang Shuangzhen on 2020/10/5.
//

#include <stdio.h>

class Test
{
    int m_i;
    int m_j;
    bool m_Status;
public:
    Test(int i, int j) : m_Status(false)
    {
        m_i = i;

        return;

        m_j = j;

        m_Status = true;
    }
    int getI()
    {
        return m_i;
    }
    int getJ()
    {
        return m_j;
    }
    int status()
    {
        return m_Status;
    }
};

int main()
{
    Test t1(1, 2);

    if( t1.status() )
    {
        printf("t1.mi = %d\n", t1.getI());
        printf("t1.mj = %d\n", t1.getJ());

    }

    return 0;
}

