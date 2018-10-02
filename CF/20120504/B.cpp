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
using namespace std;
struct nod
{
    int a,b,num;
    double res;
}node[1005];
int cmp(const void *p,const void *q)
{
    nod *a=(nod *)p;
    nod *b=(nod *)q;
    if(a->res>b->res)return -1;
    else if(a->res<b->res)return 1;
    else return a->num - b->num;

}
int main()
{
    int n,t1,t2,k,i;
    double tmp1,tmp2;
    scanf("%d%d%d%d",&n,&t1,&t2,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&node[i].a,&node[i].b);
        node[i].num=i+1;
        tmp1=1.0*t1*node[i].a/100.0*(100.0-k)+t2*node[i].b;
        tmp2=1.0*t1*node[i].b/100.0*(100.0-k)+t2*node[i].a;
        if(tmp1>tmp2)node[i].res=tmp1;
        else node[i].res=tmp2;
        node[i].res=floor(node[i].res*100.0)/100.0;
    }
    qsort(node,n,sizeof(node[0]),cmp);
    for(i=0;i<n;i++)printf("%d %.2lf\n",node[i].num,node[i].res);
    return 0;
}
