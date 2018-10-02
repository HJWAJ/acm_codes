#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const long long int mod=1000000007LL;

long long int c(long long int m,long long int n)
{
    long long int i,res=1LL;
    for(i=0;i<m;i++)
    {
        res*=(n-i);
        res/=(1+i);
        res%=mod;
    }
    return res;
}

int main()
{
    long long int n,res,i;
    while(scanf("%lld",&n)!=EOF)
    {
        res=0;
        for(i=0;i<n;i++)
        {
            res=(res+c(i,n-1+i))%mod;        
        }
        res=(2*res-n)%mod;
        printf("%lld\n",res);                 
    }    
    
    return 0;
}
