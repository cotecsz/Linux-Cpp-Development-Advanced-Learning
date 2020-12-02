//
// Created by dream on 2020/12/2.
//

#include <iostream>
#include <string>

using namespace std;

double divide(double a, double b, int* valid)
{
    const double delta = 0.000000000000001;
    double ret = 0;

    if( !((-delta < b) && (b < delta)) )
    {
        ret = a / b;

        *valid = 1;
    }
    else
    {
        *valid = 0;
    }

    return ret;
}

int main(int argc, char *argv[])
{
    int valid = 0;
    double r = divide(1, 0, &valid);

    if( valid )
    {
        cout << "r = " << r << endl;
    }
    else
    {
        cout << "Divided by zero..." << endl;
    }

    return 0;
}

