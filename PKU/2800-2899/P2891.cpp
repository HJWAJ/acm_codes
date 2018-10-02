#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
__int64 x,y,t;
__int64 extend_gcd(__int64 a, __int64 b)
{
    if (b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        __int64 d=extend_gcd(b,a%b);
        t=x;
        x=y;
        y=t-a/b*y;
        return d;
    }
}
int main()
{
    __int64 m1,m2,r1,r2,d,c,t,n,i;
    bool bo;
    while(scanf("%I64d",&n)!=EOF)
    {
        bo=0;
        scanf("%I64d%I64d",&m1,&r1);
        for(i=0;i<n-1;i++)
        {
            scanf("%I64d%I64d",&m2,&r2);
            if(bo)continue;
            d=extend_gcd(m1,m2);
            c=r2-r1;
            if(c%d)
            {
                bo=1;
                continue;
            }
            t=m2/d;
            x=(c/d*x%t+t)%t;
            r1=m1*x+r1;
            m1=m1*m2/d;
        }
        if(bo)puts("-1");
        else printf("%I64d\n",r1);
    }
    return 0;
}
