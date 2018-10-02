#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

struct nod
{
    int j,c;
    double val;       
}node[10005];

int cmp(const void *p,const void *q)
{
    nod *a=(nod *)p;
    nod *b=(nod *)q;
    if(a->val > b->val)return -1;
    else if(a->val < b->val)return 1;
    else return 0;    
}

int main()
{
    int n,i,m;
    double mm,sum;
    while(scanf("%d%d",&m,&n) && !(m==-1 && n==-1))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&node[i].j,&node[i].c);
            //if(node[i].c==0)node[i].val=100005.0;
            //else 
            node[i].val=(double)node[i].j/(double)node[i].c;                
        }                           
        qsort(node,n,sizeof(node[0]),cmp);
        sum=0;i=0;mm=m;
        for(i=0;i<n;i++)
        {
            if(mm>=node[i].c)
            {
                mm-=node[i].c;
                sum+=node[i].j;                 
            }                
            else
            {
                sum+=mm*node[i].val;
                break;    
            }
        }
        printf("%.3lf\n",sum);
    }
    
    return 0;
}
