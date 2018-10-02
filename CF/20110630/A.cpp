#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char str[105],s[11][11],tmp[15];
    int i,j;
    scanf("%s",str);
    for(i=0;i<10;i++)scanf("%s",s[i]);
    for(i=0;i<8;i++)
    {
        for(j=0;j<10;j++)
            tmp[j]=str[10*i+j];
        tmp[10]='\0';
        for(j=0;j<10;j++)
            if(!strcmp(tmp,s[j]))
            {
                printf("%d",j);
                break;
            }
    }
    printf("\n");
    return 0;
}
