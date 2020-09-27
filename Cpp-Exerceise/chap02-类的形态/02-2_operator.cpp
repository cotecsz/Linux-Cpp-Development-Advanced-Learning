//
// Created by Yang Shuangzhen on 2020/9/27.
//

#include "02-2_operator.h"

bool Operator::setOperator(char op)
{
    bool ret = false;

    if( (op == '+') || (op == '-') || (op == '*') || (op == '/') )
    {
        ret = true;
        m_Op = op;
    }
    else
    {
        m_Op = '\0';
    }

    return ret;
}

void Operator::setParameter(double p1, double p2)
{
    m_P1 = p1;
    m_P2 = p2;
}

bool Operator::result(double& r)
{
    bool ret = true;

    switch( m_Op )
    {
        case '/':
            if( (-0.000000001 < m_P2) && (m_P2 < 0.000000001) )
            {
                ret = false;
            }
            else
            {
                r = m_P1 / m_P2;
            }
            break;
        case '+':
            r = m_P1 + m_P2;
            break;
        case '*':
            r = m_P1 * m_P2;
            break;
        case '-':
            r = m_P1 - m_P2;
            break;
        default:
            ret = false;
            break;
    }

    return ret;
}
