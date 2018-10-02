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
int n;
double a,d;
struct nod
{
    int i;
    double t;
    double v;
    double ts;
}node[100005];
int cmp(const void *p,const void *q)
{
    nod *a=(nod *)p;
    nod *b=(nod *)q;
    if(a->t < b->t)return -1;
    else if(a->t == b->t)return 0;
    return 1;
}
int cmp2(const void *p,const void *q)
{
    nod *a=(nod *)p;
    nod *b=(nod *)q;
    if(a->i < b->i)return -1;
    else if(a->i == b->i)return 0;
    return 1;
}
int main()
{
    int i;
    double tm,dd,dis;
    scanf("%d%lf%lf",&n,&a,&d);
    for(i=0;i<n;i++)
    {
        scanf("%lf%lf",&node[i].t,&node[i].v);
        node[i].i=i;
    }
    dis=d;
    qsort(node,n,sizeof(node[0]),cmp);
    for(i=0;i<n;i++)
    {
        d=dis;
        tm=node[i].v/a;
        //cout<<tm<<endl;
        dd=tm*tm*a/2;
        //cout<<dd<<endl;
        if(dd<d)
        {
            d-=dd;
            tm+=(d/node[i].v);
        }
        else
        {
            tm=sqrt(d*2.0/a);
        }
        //cout<<tm<<endl;
        if(i==0)node[i].ts=node[i].t+tm;
        else if(node[i].t+tm>node[i-1].ts)node[i].ts=node[i].t+tm;
        else node[i].ts=node[i-1].ts;
    }
    qsort(node,n,sizeof(node[0]),cmp2);
    for(i=0;i<n;i++)printf("%lf\n",node[i].ts);
    return 0;
}
