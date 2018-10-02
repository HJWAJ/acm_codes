#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

struct nod
{
    int num[205];
    int cnt;      
}node[40005],ans[205];

int cmp(const void *p,const void *q)
{
    nod *a=(nod *)p;
    nod *b=(nod *)q;
    int i,num=a->cnt>b->cnt?a->cnt:b->cnt;
    for(i=0;i<=num;i++)
    {
        if(a->num[i] == b->num[i])continue;
        else return a->num[i] - b->num[i];                  
    }    
}

int flag[205];

int main()
{
    int n,nn,i,j,f=0,dis,tmp,ftmp;
    bool bo=0;
    scanf("%d",&n);
    nn=n*(n-1)/2;
    memset(flag,0,sizeof(flag));
    memset(node,0,sizeof(node));
    memset(ans,0,sizeof(ans));
    for(i=0;i<nn;i++)
    {
        scanf("%d",&node[i].cnt);
        for(j=0;j<node[i].cnt;j++)scanf("%d",&node[i].num[j]);
        sort(node[i].num,node[i].num+node[i].cnt);                 
    }
    qsort(node,nn,sizeof(node[0]),cmp);
    for(i=0;i<nn;i++)
    {
        for(j=0;j<node[i].cnt;j++)
        {
            flag[node[i].num[j]]++;
            if(flag[node[i].num[j]]==n-1)
            {
                ans[f].num[ans[f].cnt]=node[i].num[j];
                ans[f].cnt++;
                bo=1;                             
            }
        }
        if(bo==1)
        {
            for(j=0;j<ans[f].cnt;j++)printf("%d ",ans[f].num[j]);
            printf("\n");
            system("pause");
            f++;
            bo=0;         
        }                 
    }
    ftmp=f;
    if(f<n)
    {
        dis=n-f;
        while(dis-(ans[f-1].cnt-1)>0)
        {
            dis-=(ans[f-1].cnt-1);
            f--;            
        }
        tmp=dis;
        ans[f-1].cnt-=dis;       
    }
    for(i=0;i<f;i++)
    {
        printf("%d",ans[i].cnt);
        for(j=0;j<ans[i].cnt;j++)printf(" %d",ans[i].num[j]);
        printf("\n");                 
    }
    for(i=0;i<tmp;i++)printf("1 %d\n",ans[f-1].num[ans[f-1].cnt+i]);
    for(i=f;i<ftmp;i++)
        for(j=0;j<ans[i].cnt;j++)
            printf("1 %d\n",ans[i].num[j]);
    while(1);
    return 0;
}
