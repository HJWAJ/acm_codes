#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

struct nod
{
    int num,mark;       
}node[105];

int cmp(const void *p,const void *q)
{
    nod *a=(nod *)p;
    nod *b=(nod *)q;
    if(a->mark != b->mark)return a->mark - b->mark;
    return a->num - b->num;    
}

int main()
{
    int n,m,i,j,val[1005],flag=0,cnt;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&node[i].mark);
        node[i].num=i+1;                
    }
    node[m].mark=99999999;
    node[m].num=m+1;
    qsort(node,m,sizeof(node[0]),cmp);
    i=0;
    while(i<n)
    {
        cnt=flag;
        for(;cnt<m;i++)
        {
            cnt++;
            val[i]=node[cnt-1].num;                  
        }
        for(cnt=flag;cnt<m;cnt++)node[cnt].mark--;
        while(node[flag].mark==0)flag++;
        if(i<n && flag==m){printf("-1\n");exit(0);}
    }
    if(val[n-1]==val[0])val[n-1]++;
    if(val[n-1]==val[n-2])printf("-1\n");
    else
    {
        for(i=0;i<n;i++)printf("%d ",val[i]);
        printf("\n");
    }
    
    //system("pause");
    return 0;
}
