/*
ID: hjw00002
PROG: holstein
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

struct nod
{
    int res,cnt,ans[30];       
}node[50000];

int cmp(const void *p1,const void *p2)
{
    nod *a=(nod *)p1;
    nod *b=(nod *)p2;
    if(a->cnt != b->cnt)return a->cnt - b->cnt;
    for(int i=0;i<a->cnt;i++)
        if(a->ans[i] != b->ans[i])return a->ans[i] - b->ans[i];    
}

bool finished(int v[],int sum[],int num)
{
    int i;
    for(i=0;i<num;i++)
        if(v[i]>sum[i])return 0;
    return 1;
}

int main()
{
    freopen("holstein.in","r",stdin);
    freopen("holstein.out","w",stdout);
    int flag[16]={1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767};
    int V,G,v[30],g[20][30],sum[30],i,j,k,num=0;
    memset(node,0,sizeof(node));
    scanf("%d",&V);
    for(i=0;i<V;i++)scanf("%d",v+i);
    scanf("%d",&G);
    for(i=0;i<G;i++)
        for(j=0;j<V;j++)
            scanf("%d",&g[i][j]);
    for(i=1;i<=flag[G-1];i++)
    {
        memset(sum,0,sizeof(sum));
        for(j=0;j<G;j++)
        {
            if((i>>j)&1)
                for(k=0;k<V;k++)sum[k]+=g[j][k];                  
        }
        if(finished(v,sum,V))node[num++].res=i;                       
    }
    for(i=0;i<num;i++)
        for(j=0;j<G;j++)
            if((node[i].res>>j)&1)
            {
                node[i].cnt++;
                node[i].ans[node[i].cnt-1]=j+1;                      
            }
    qsort(node,num,sizeof(node[0]),cmp);
    printf("%d",node[0].cnt);
    for(i=0;i<node[0].cnt;i++)printf(" %d",node[0].ans[i]);
    printf("\n");
    
    //system("pause");
    return 0;
}
