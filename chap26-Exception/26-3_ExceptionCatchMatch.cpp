//
// Created by dream on 2020/12/2.
//

#include <iostream>
#include <string>

using namespace std;

void Demo1()
{
    try
    {
        throw 'c';
    }
    catch(char c)
    {
        cout << "catch(char c)" << endl;
    }
    catch(short c)
    {
        cout << "catch(short c)" << endl;
    }
    catch(double c)
    {
        cout << "catch(double c)" << endl;
    }
    catch(...)
    {
        cout << "catch(...)" << endl;
    }
}

void Demo2()
{
    throw string("D.T.Software");
}

int main(int argc, char *argv[])
{
    Demo1();

    try
    {
        Demo2();
    }
    catch(char* s)
    {
        cout << "catch(char *s)" << endl;
    }
    catch(const char* cs)
    {
        cout << "catch(const char *cs)" << endl;
    }
    catch(string ss)
    {
        cout << "catch(string ss)" << endl;
    }

    return 0;
}

