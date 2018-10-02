/*
ID: hjw00002
PROG: ariprog
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;

bool val[150000];
int list[100000];
struct ans
{
    int a0,d;       
}res[10050];

bool isseq(int a0,int d,int n)
{
    int i;
    int res=a0+(n-1)*d;
    for(i=0;i<n-1;i++)
    {
        if(!val[res])return 0;
        res-=d;   
    }     
    return 1;
}

int cmp(const void *p1,const void *p2)
{
    ans *a=(ans *)p1;
    ans *b=(ans *)p2;
    if(a->d - b->d!=0)return a->d - b->d;
    return a->a0 - b->a0;   
}

int main()
{
    freopen("ariprog.in","r",stdin);
    freopen("ariprog.out","w",stdout);
    int n,m,i,j,len=0,limit,flag=0;
    scanf("%d%d",&n,&m);
    memset(val,0,sizeof(val));
    limit=2*m*m;
    for(i=0;i<=m;i++)
        for(j=0;j<=i;j++)
            val[i*i+j*j]=1;
    for(i=0;i<=limit;i++)
        if(val[i]==1)list[len++]=i;
    for(i=0;i<len;i++)
        for(j=i+1;j<len;j++)
        {
            if(list[i]+(n-1)*(list[j]-list[i])>limit)break;
            if(isseq(list[i],list[j]-list[i],n))
            {
                res[flag].a0=list[i];
                res[flag++].d=list[j]-list[i];
            }
        }
    qsort(res,flag,sizeof(res[0]),cmp);
    for(i=0;i<flag;i++)printf("%d %d\n",res[i].a0,res[i].d);
    if(flag==0)printf("NONE\n");
    
    //system("pause");
    return 0;
}
