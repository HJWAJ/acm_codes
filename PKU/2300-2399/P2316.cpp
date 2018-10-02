#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int i;
    char str[100],s[100];
    gets(str);
    while(scanf("%s",s)!=EOF)
    {
        i=0;
        while(s[i]!='\0')
        {
            str[i]=(str[i]+s[i]-2*'0')%10+'0';
            i++;
        }
    }
    printf("%s\n",str);

    return 0;
}

