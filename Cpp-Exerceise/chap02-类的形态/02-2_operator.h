//
// Created by Yang Shuangzhen on 2020/9/27.
//

#ifndef CPP_EXERCEISE_02_2_OPERATOR_H
#define CPP_EXERCEISE_02_2_OPERATOR_H

class Operator
{
private:
    char m_Op;
    double m_P1;
    double m_P2;

public:
    bool setOperator(char op);
    void setParameter(double p1, double p2);
    bool result(double& r);
};

#endif //CPP_EXERCEISE_02_2_OPERATOR_H
