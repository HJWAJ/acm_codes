#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct nod
{
    int num,mark;       
}node[200005];

int cmp1(const void *p,const void *q)
{
    nod *a=(nod *)p;
    nod *b=(nod *)q;
    if(a->mark != b->mark)return a->mark - b->mark;
    return a->num - b->num;    
}

int cmp2(const void *p,const void *q)
{
    nod *a=(nod *)p;
    nod *b=(nod *)q;
    if(a->mark != b->mark)return a->mark - b->mark;
    return b->num - a->num;    
}

int main()
{
    int n,a,b,val[200005],i;
    scanf("%d%d%d",&n,&a,&b);
    for(i=0;i<n;i++)
    {
        scanf("%d",&node[i].mark);
        node[i].num=i;                
    }
    if(a>b)
    {
        qsort(node,n,sizeof(node[0]),cmp1);
        for(i=0;i<a;i++)val[node[i].num]=1;
        for(i=a;i<a+b;i++)val[node[i].num]=2;        
    }
    else if(a<b)
    {
        qsort(node,n,sizeof(node[0]),cmp2);
        for(i=0;i<b;i++)val[node[i].num]=2;
        for(i=b;i<a+b;i++)val[node[i].num]=1;    
    }
    else
    {
        for(i=0;i<a;i++)val[node[i].num]=1;
        for(i=a;i<a+b;i++)val[node[i].num]=2;    
    }
    for(i=0;i<n;i++)printf("%d ",val[i]);
    printf("\n");
    
    //system("pause");
    return 0;
}
