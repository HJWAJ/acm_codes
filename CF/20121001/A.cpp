#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
using namespace std;
struct nod
{
    int a;
    int b;
}node[1005];
bool cmp(nod a,nod b)
{
    if(a.a!=b.a)return a.a<b.a;
    return a.b>b.b;
}
int main()
{
    int s,n,i;
    scanf("%d%d",&s,&n);
    for(i=0;i<n;i++)scanf("%d%d",&node[i].a,&node[i].b);
    sort(node,node+n,cmp);
    for(i=0;i<n;i++)
    {
        if(s>node[i].a)s+=node[i].b;
        else break;
    }
    if(i==n)puts("YES");
    else puts("NO");
    return 0;
}
