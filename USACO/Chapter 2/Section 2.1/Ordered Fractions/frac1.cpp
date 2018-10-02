/*
ID: hjw00002
PROG: frac1
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
    int p,q;
    double val;       
}node[5000005];

int cmp(const void *p1,const void *p2)
{
    nod *a=(nod *)p1;
    nod *b=(nod *)p2;
    return (a->val > b->val)?1:-1;  
}

bool isp(int a,int b)
{
    int val[200],flag1,flag2,aa,bb,i;
    memset(val,0,sizeof(val));
    flag1=flag2=0;
    aa=int(sqrt(double(a)));
    bb=int(sqrt(double(b)));
    for(i=2;i<=aa;i++)
        if(a%i==0){val[i]=1;val[a/i]=1;}
    val[a]=1;
    if(val[b])return 0;
    for(i=2;i<=bb;i++)
        if(b%i==0)if(val[i] || val[b/i])return 0;
    return 1;
}

int main()
{
    //freopen("frac1.in","r",stdin);
    //freopen("frac1.out","w",stdout);
    int n,i,j,flag=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)             
        for(j=1;j<i;j++)
        {
            if(isp(i,j))
            {
                node[flag].p=j;
                node[flag].q=i;
                node[flag].val=double(node[flag].p)/double(node[flag].q);
                flag++;            
            }                 
        }
    qsort(node,flag,sizeof(node[0]),cmp);
    printf("0/1\n");
    for(i=0;i<flag;i++)printf("%d/%d\n",node[i].p,node[i].q);
    printf("1/1\n");
    
    system("pause");
    return 0;
}
