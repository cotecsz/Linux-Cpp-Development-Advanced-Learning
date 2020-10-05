//
// Created by Yang Shuangzhen on 2020/10/5.
//

#include <stdio.h>
#include <string.h>

char* strcpy(char* buf, const char* str, unsigned int n)
{
    return strncpy(buf, str, n);
}

int main()
{
    const char* s = "D.T.Software";
    char buf[8] = {0};

    //strcpy(buf, s);
    strcpy(buf, s, sizeof(buf)-1);

    printf("%s\n", buf);

    return 0;
}

