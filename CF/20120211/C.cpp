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
    int a,num,flag;
}node[100005];
int cmp(const void *p,const void *q)
{
    nod *a=(nod *)p;
    nod *b=(nod *)q;
    return a->a - b->a;
}
int main()
{
    int n,i,x=0,y=0,cnt1=0,cnt2=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&node[i].a);
        node[i].num=i+1;
    }
    qsort(node,n,sizeof(node[0]),cmp);
    for(i=0;i<n;i++)
    {
        if(i%4==0 || i%4==3)
        {
            x+=node[i].a;
            node[i].flag=1;
        }
        else
        {
            y+=node[i].a;
            node[i].flag=2;
        }
    }
    if(n&1 && abs(x-y)>node[n-1].a)
    {
        if(node[n-1].flag==2)node[n-1].flag=1;
        else node[n-1].flag=2;
    }
    for(i=0;i<n;i++)
    {
        if(node[i].flag==1)cnt1++;
        else cnt2++;
    }
    printf("%d\n",cnt1);
    for(i=0;i<n;i++)
        if(node[i].flag==1)printf("%d ",node[i].num);
    puts("");
    printf("%d\n",cnt2);
    for(i=0;i<n;i++)
        if(node[i].flag==2)printf("%d ",node[i].num);
    puts("");
    return 0;
}
