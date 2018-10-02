#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
using namespace std;
__int64 calc(__int64 n,__int64 k)
{
    __int64 res=0,kk=1;
    while(n/kk)
    {
        res+=n/kk;
        kk*=k;
    }
    return res;
}
int main()
{
    __int64 n,k,l=0,r=1000000005,mid,num;
    scanf("%I64d%I64d",&n,&k);
    while(l<r-1)
    {
        mid=(l+r)/2;
        num=calc(mid,k);
        if(num>n)r=mid;
        else l=mid;
    }
    if(l==r)printf("%I64d\n",l);
    else if(calc(l,k)>=n)printf("%I64d\n",l);
    else printf("%I64d\n",r);
    return 0;
}
