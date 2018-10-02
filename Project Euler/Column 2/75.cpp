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
/**
  * x^2+y^2=z^2
  * x=k(a^2-b^2)
  * y=2kab
  * z=k(a^2+b^2)
  */
long long bo[1500005];
struct nod
{
    pair<long long,long long> p;
    long long t;
    bool operator < (const nod b) const
    {
        if(p.first < b.p.first)return 1;
        if(p.first == b.p.first && p.second < b.p.second)return 1;
        if(p.first == b.p.first && p.second == b.p.second && t<b.t)return 1;
        return 0;
    }
}node;
set< nod > s;
int main()
{
    long long a,b,k,i,cnt=0,t1,t2;
    for(a=2;a*a<=1500000;a++)
        for(b=1;b<a;b++)
        {
            if(2*a*a+2*a*b>1500000)break;
            for(k=1;2*k*a*(a+b)<=1500000;k++)
            {
                t1=k*(a*a-b*b);
                t2=a*2*b*k;
                if(t1>t2)swap(t1,t2);
                node.p=make_pair(t1,t2);
                node.t=k*(a*a+b*b);
                if(s.find(node)==s.end())
                {
                    s.insert(node);
                    bo[k*2*a*(a+b)]++;
                }
            }
        }
    for(i=1;i<1500001;i++)
        if(bo[i]==1)
            cnt++;
    printf("%lld\n",cnt);
    return 0;
}
