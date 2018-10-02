#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <stack>
#include <set>
using namespace std;
struct speed
{
    double slow,fast;
    bool operator < (const speed b) const
    {
        if(slow!=b.slow)return slow < b.slow;
        return fast < b.fast;
    }
}sp[10005];
int main()
{
    //freopen("in.in","r",stdin);
    int t,n,cnt,i,j;
    double dd,l,w,nowtime,a,b,c,d,tmp,min,x,y,ans;
    scanf("%d",&t);
    while(t--)
    {
        min=1e15;
        scanf("%d%lf%lf%lf",&n,&dd,&l,&w);
        for(i=0;i<n;i++)scanf("%lf%lf",&sp[i].slow,&sp[i].fast);
        if(n*dd>l)
        {
            puts("No solution");
            continue;
        }
        sort(sp,sp+n);
        nowtime=0;
        ans=0;
        for(i=0;i<n;i++)
        {
            nowtime+=sp[i].slow*dd;
            ans+=sp[i].fast*dd;
        }
        l-=n*dd;
        if(nowtime+l*sp[0].slow>w)
        {
            puts("No solution");
            continue;
        }
        w-=nowtime;
        cnt=1;
        for(i=1;i<n;i++)
        {
            if(sp[i].fast>=sp[cnt-1].fast && sp[i].slow>=sp[cnt-1].slow)continue;
            else
            {
                sp[cnt].fast=sp[i].fast;
                sp[cnt].slow=sp[i].slow;
                cnt++;
            }
        }
        //cout<<l<<' '<<w<<' '<<sp[0].slow<<' '<<sp[0].fast<<endl;
        for(i=0;i<cnt;i++)
        {
            a=sp[i].fast;
            b=sp[i].slow;
            if(b*l<=w)
            {
                tmp=a*l;
                if(tmp<min)min=tmp;
            }
        }
        for(i=0;i<cnt;i++)
            for(j=i+1;j<cnt;j++)
            {
                a=sp[i].fast;b=sp[i].slow;
                c=sp[j].fast;d=sp[j].slow;
                if(b*l>w)continue;
                if(d*l<=w)
                {
                    tmp=c*l;
                    if(tmp<min)min=tmp;
                }
                else
                {
                    y=(b*l-w)/(b-d);
                    x=l-y;
                    tmp=x*a+y*c;
                    if(tmp<min)min=tmp;
                }
            }
        ans+=min;
        printf("%.2lf\n",ans);
    }
    return 0;
}
