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
#include<ctime>
#include<windows.h>
using namespace std;
const __int64 inf=1LL<<62;
struct node
{
    __int64 p,q;
    bool operator < (const node b) const
    {
        if(p<b.p)return 1;
        if(p== b.p && q<b.q)return 1;
        return 0;
    }
    bool operator == (const node b) const
    {
        if(p== b.p && q==b.q)return 1;
        return 0;
    }
};
set<node> s;
__int64 gcd(__int64 a,__int64 b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int n,i;
    __int64 k,b,d;
    node nd;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%I64d%I64d",&k,&b);
        if(k==0)continue;
        d=gcd(k,b);
        b/=d;
        k/=d;
        if(b<0)
        {
            b=-b;
            k=-k;
        }
        nd.p=b;
        nd.q=k;
        s.insert(nd);
    }
    printf("%d\n",(int)s.size());
    return 0;
}
