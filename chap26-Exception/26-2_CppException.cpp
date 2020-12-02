//
// Created by dream on 2020/12/2.
//

#include <iostream>
#include <string>

using namespace std;

double divide(double a, double b)
{
    const double delta = 0.000000000000001;
    double ret = 0;

    if( !((-delta < b) && (b < delta)) )
    {
        ret = a / b;
    }
    else
    {
        throw 0;
    }

    return ret;
}

int main(int argc, char *argv[])
{
    try
    {
        double r = divide(1, 0);

        cout << "r = " << r << endl;
    }
    catch(...)
    {
        cout << "Divided by zero..." << endl;
    }

    return 0;
}


