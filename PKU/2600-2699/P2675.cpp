#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;

struct song
{
    int  id;
    int  ln;
    double fr;
}a[100000];

int cmp(const void *p1,const void *p2)
{
    if((*(struct song *)p2).fr > (*(struct song *)p1).fr)return 1;
    if(fabs((*(struct song *)p2).fr-(*(struct song *)p1).fr)<0.000001)return 0;
    return -1;      
}

int main()
{
    int i,n,num;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++) 
        {
            scanf("%d%d%lf",&a[i].id,&a[i].ln,&a[i].fr);
            a[i].fr/=a[i].ln;
        }
        scanf("%d",&num);
        qsort(a,n,sizeof(a[0]),cmp);
        printf("%d\n",a[num-1].id);
    }
    
    return 0;
}                     
