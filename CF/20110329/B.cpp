#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n,k,t,a[105],i,tmp,num;
    scanf("%d%d%d",&n,&k,&t);
    memset(a,0,sizeof(a));
    tmp=n*k*t/100;
    num=tmp/k;
    for(i=0;i<num;i++)a[i]=k;
    if(tmp%k)a[num]=tmp%k;
    printf("%d",a[0]);
    for(i=1;i<n;i++)printf(" %d",a[i]);
    printf("\n");
    
    //system("pause");
    return 0;
}
