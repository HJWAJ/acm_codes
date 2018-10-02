#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct mi
{
    int num,cost;
}node[1005];
int cmp(const void *p, const void *q)
{
    return ((mi *)p)->cost - ((mi *)q)->cost;
}
int main()
{
    int n,m,i,t,sum;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d%d",&m,&n);
        for(i=0;i<n;i++)scanf("%d%d",&node[i].cost,&node[i].num);
        qsort(node,n,sizeof(node[0]),cmp);
        i=0;
        while(m>=node[i].cost*node[i].num)
        {
            sum+=node[i].num;
            m-=node[i].cost*node[i].num;
            i++;
        }
        printf("%.2lf\n",sum+m*1.0/node[i].cost);
    }
    return 0;
}
