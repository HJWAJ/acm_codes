#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char s[105];
    int len;
    while(scanf("%s",s)!=EOF)    
    {
        len=strlen(s);
        if(len<3)printf("byte\n");
        else if(len==3)
        {
            if(strcmp(s,"128")<0)printf("byte\n");
            else printf("short\n");
        }
        else if(len<5)printf("short\n");
        else if(len==5)
        {
            if(strcmp(s,"32768")<0)printf("short\n");
            else printf("int\n");
        }
        else if(len<10)printf("int\n");
        else if(len==10)
        {
            if(strcmp(s,"2147483648")<0)printf("int\n");
            else printf("long\n");
        }
        else if(len<19)printf("long\n");
        else if(len==19)
        {
            if(strcmp(s,"9223372036854775808")<0)printf("long\n");
            else printf("BigInteger\n");
        }
        else printf("BigInteger\n");
    }
    
    return 0;
}
