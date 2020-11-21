//
// Created by dream on 2020/11/21.
//

#include <iostream>
#include <string>

using namespace std;

class Channel
{
public:
    virtual bool open() = 0;
    virtual void close() = 0;
    virtual bool send(char* buf, int len) = 0;
    virtual int receive(char* buf, int len) = 0;
};

int main()
{
    return 0;
}
