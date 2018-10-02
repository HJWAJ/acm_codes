#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    __int64 n,flag,s[1005],i;
    while(scanf("%I64d",&n)!=EOF)
    {
        if(n==0){printf("0\n");continue;}
        i=flag=0;
        memset(s,0,sizeof(s));
        while(n)
        {
            s[i]=n%2;
            if(n<0)s[i]=-s[i];
            n-=s[i];
            n/=-2;
            i++;
        }
        flag=i;
        for(i=0;i<flag/2;i++)swap(s[i],s[flag-1-i]);
        for(i=0;i<flag;i++)printf("%I64d",s[i]);
        printf("\n");                          
    }    
    
    return 0;
}
