#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std;
__int64 c(__int64 n,__int64 m)
{
    __int64 res=1;
    if(m>n)return 0;
    if(m>n/2)m=n-m;
    int i;
    for(i=0;i<m;i++)
    {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
int main()
{
    __int64 m,n,t,res=0,i;
    scanf("%I64d%I64d%I64d",&n,&m,&t);
    for(i=4;i<=t-1;i++)
    {
        res+=c(n,i)*c(m,t-i);
    }
    printf("%I64d\n",res);
    return 0;
}
