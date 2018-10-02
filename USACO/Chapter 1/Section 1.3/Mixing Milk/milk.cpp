/*
ID: hjw00002
PROG: milk
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

struct farmer
{
    int p,a;       
}f[5000];

int cmp(const void *p1,const void *p2)
{
    farmer *a=(farmer *)p1;
    farmer *b=(farmer *)p2;
    return a->p - b->p;
}

int main()
{
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
    int m,n,i,sum=0;
    scanf("%d%d",&m,&n);
    for(i=0;i<n;i++)scanf("%d%d",&f[i].p,&f[i].a);
    qsort(f,n,sizeof(f[0]),cmp);
    //for(i=0;i<n;i++)printf("%d %d\n",f[i].p,f[i].a);
    i=0;
    while(m>0)
    {
        if(m<f[i].a)
        {
            sum+=(f[i].p*m);
            m=0;            
        }
        else 
        {
            sum+=(f[i].p*f[i].a);
            m-=f[i].a;     
        }
        i++;
    }
    printf("%d\n",sum);
    
    //system("pause");
    return 0;
}
