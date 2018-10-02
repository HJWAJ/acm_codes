#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
struct nod
{
    __int64 id,val;
}node[100005];
int cmp(const void *p,const void *q)
{
    nod *a=(nod *)p;
    nod *b=(nod *)q;
    return a->val - b->val;
}
int main()
{
    __int64 n,d,a,b,x,y,i,cnt=0,sum=0;
    scanf("%I64d%I64d",&n,&d);
    scanf("%I64d%I64d",&a,&b);
    for(i=0;i<n;i++)
    {
        node[i].id=i;
        scanf("%I64d%I64d",&x,&y);
        node[i].val=x*a+y*b;
    }
    qsort(node,n,sizeof(node[0]),cmp);
    //for(i=0;i<n;i++)cout<<i<<' '<<node[i].id<<' '<<node[i].val<<endl;
    for(cnt=0;cnt<n;cnt++)
    {
        sum+=node[cnt].val;
        if(sum>d)break;
    }
    printf("%I64d\n",cnt);
    for(i=0;i<cnt-1;i++)printf("%I64d ",node[i].id+1);
    if(cnt>0)printf("%I64d\n",node[cnt-1].id+1);
    return 0;
}
