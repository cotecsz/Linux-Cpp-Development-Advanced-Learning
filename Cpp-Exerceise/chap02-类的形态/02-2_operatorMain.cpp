//
// Created by Yang Shuangzhen on 2020/9/27.
//

#include <stdio.h>
#include "02-2_operator.h"

int main()
{
    Operator op;
    double r = 0;

    op.setOperator('/');
    op.setParameter(9, 3);

    if( op.result(r) )
    {
        printf("r = %lf\n", r);
    }
    else
    {
        printf("Calculate error!\n");
    }

    return 0;
}


