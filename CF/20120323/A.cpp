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
struct nod
{
    int p,t,num;
}node[105];
int cmp(const void *p,const void *q)
{
    nod *a=(nod *)p;
    nod *b=(nod *)q;
    if(a->p != b->p)return b->p - a->p;
    return a->t - b->t;
}
int main()
{
    int n,k,i;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&node[i].p,&node[i].t);
        node[i].num=i;
    }
    if(n==1)
    {
        puts("1");
        return 0;
    }
    qsort(node,n,sizeof(node[0]),cmp);
    k-=2;
    while(k>=0)
    {
        if(node[k].p==node[k+1].p && node[k].t==node[k+1].t)k--;
        else break;
    }
    k+=2;
    i=1;
    for(;k<n;k++)
    {
        if(node[k].p==node[k-1].p && node[k].t==node[k-1].t)
        {
            i++;
            continue;
        }
        else break;
    }
    printf("%d\n",i);
    return 0;
}
