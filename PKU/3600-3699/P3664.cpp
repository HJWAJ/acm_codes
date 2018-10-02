#include<iostream>
#include<stdlib.h>
using namespace std;

struct cow
{
    int vote1;
    int vote2;
    int num;
}cowp[50000];

int cmp1(const void *p1,const void *p2)
{
    struct cow *c=(cow *)p1;
    struct cow *d=(cow *)p2;
    return d->vote1 - c->vote1;
}

int cmp2(const void *p1,const void *p2)
{
    struct cow *c=(cow *)p1;
    struct cow *d=(cow *)p2;
    return d->vote2 - c->vote2;
}

int main()
{
    int n,k,i;
    
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&cowp[i].vote1,&cowp[i].vote2);
        cowp[i].num=i+1;    
    }
    
    qsort(cowp,n,sizeof(cowp[0]),cmp1);
    qsort(cowp,k,sizeof(cowp[0]),cmp2);  
    printf("%d\n",cowp[0].num);  
    
    system("pause");
    return 0;
}
