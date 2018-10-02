#include<iostream>
#include<cstdio>
using namespace std;

long long int c(long long int n,long long int m)
{
    if(m==0)return 1;
    long long int i;
    long long int res=1;
    for(i=1;i<=m;i++)
    {
        res=res*(n+1-i)/i;      
    }
    return res;
}

int main()
{
    long long int m,n;
    while(scanf("%lld%lld",&n,&m)!=EOF && !(m==0 && n==0))
    {
        printf("%lld\n",c(n+m,m<n?m:n));
    }    
    //*/
    //system("pause");
    return 0;
}
