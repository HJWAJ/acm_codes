#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int c(int n,int m)
{
    long long int res=1;
    int i;
    for(i=1;i<=m;i++)
    {
        res*=n+1-i;
        res/=i;                
    }
    return res;    
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) && !(n==0 &&m==0))
    {
        if(m==0)printf("1\n");
        else
        {
            if(m>n/2)m=n-m;
            printf("%d\n",c(n,m));
        }                          
    }    
    
    return 0;
}
