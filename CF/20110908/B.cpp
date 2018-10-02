#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
struct nod
{
    char s[15];
    int ene[25];
    int num;
    int id;
}node[25];
int cmp(const void *p,const void *q)
{
    nod *a=(nod *)p;
    nod *b=(nod *)q;
    return a->num - b->num;
}
int cmp2(const void *p,const void *q)
{
    nod *a=(nod *)p;
    nod *b=(nod *)q;
    return strcmp(a->s,b->s);
}
bool check(int n)
{
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<node[i].num;j++)
            for(k=0;k<n;k++)
                if(node[i].ene[j]==node[k].id)return 0;
    return 1;
}
int main()
{
    int m,n,i,j,k,x,y;
    char tmp1[15],tmp2[15];
    memset(node,0,sizeof(node));
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%s",node[i].s);
        node[i].id=i;
    }
    for(i=0;i<m;i++)
    {
        scanf("%s%s",tmp1,tmp2);
        for(j=0;j<n;j++)
            if(!strcmp(node[j].s,tmp1))x=j;
        for(j=0;j<n;j++)
            if(!strcmp(node[j].s,tmp2))y=j;
        node[x].ene[node[x].num]=y;
        node[x].num++;
        node[y].ene[node[y].num]=x;
        node[y].num++;
    }
    qsort(node,n,sizeof(node[0]),cmp);
    while(!check(n))
    {
        n--;
        for(i=0;i<n;i++)
        {
            for(j=0;j<node[i].num;j++)
            {
                if(node[i].ene[j]==node[n].id)
                {
                    node[i].num--;
                    for(k=j+1;k<node[i].num;k++)node[i].ene[k-1]=node[i].ene[k];
                }
            }
        }
    }
    qsort(node,n,sizeof(node[0]),cmp2);
    printf("%d\n",n);
    for(i=0;i<n;i++)puts(node[i].s);
    return 0;
}
