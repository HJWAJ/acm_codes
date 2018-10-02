#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
__int64 getfirst(__int64 n)
{
    __int64 res=0;
    while(n)
    {
        res=n%10;
        n/=10;
    }
    return res;
}
__int64 getlen(__int64 n)
{
    __int64 res=0;
    while(n)
    {
        n/=10;
        res++;
    }
    return res;
}
__int64 calc(__int64 n)
{
    if(n==0)return 0;
    if(n<10)return n;
    __int64 first=getfirst(n),last=n%10;
    if(first>last)return n/10+8;
    return n/10+9;
}
int main()
{
    __int64 l,r;
    scanf("%I64d%I64d",&l,&r);
    printf("%I64d\n",calc(r)-calc(l-1));
    return 0;
}
