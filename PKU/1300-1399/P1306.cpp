#include<iostream>
using namespace std;

int a[200];

void multi(int n)
{
    int i;
    for(i=0;i<200;i++)a[i]*=n;
    for(i=0;i<199;i++)
    {
        a[i+1]+=(a[i]/10);
        a[i]%=10;                   
    }     
}

void divide(int n)
{
    int i;
    for(i=199;i>=0;i--)
    {
        a[i-1]+=(a[i]%n*10);
        a[i]/=n;                   
    }     
}

void c(int n,int m)
{
    int i=0;
    int nn=n,mm;
    memset(a,0,sizeof(a));
    while(nn)
    {
        a[i]=nn%10;
        i++;
        nn/=10;         
    }
    for(i=n-1;i>n-m;i--)multi(i);
    for(i=2;i<=m;i++)divide(i);
    for(i=199;i>=0;i--)
        if(a[i]!=0)break;
    printf("%d things taken %d at a time is ",n,m);
    for(;i>=0;i--)printf("%d",a[i]);
    printf(" exactly.\n");
}

int main()
{
    /*/
    int i;
    memset(a,0,sizeof(a));
    for(i=0;i<9;i++)scanf("%d",&a[i]);
    int n=9;
    divide(n);
    for(i=0;i<9;i++)printf("%d",a[i]);
    //*/
    int m,n;
    while(scanf("%d%d",&n,&m)!=EOF && !(m==0 && n==0))
    {
        if(n==m || m==0)printf("%d things taken %d at a time is 1 exactly.\n",n,m);
        else c(n,m);                               
    }    
    //*/
    system("pause");
    return 0;
}
