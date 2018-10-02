#include<iostream>
#include<stdlib.h>
using namespace std;

int cmp(const void *a,const void *b)
{
    return *(int *)b - *(int *)a;    
}

int main()
{
    int n,b,i;
    int a[20000],sum=0;
    scanf("%d%d",&n,&b);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    i=0;
    while(sum<b)
    {
        sum+=a[i];
        i++;            
    }    
    printf("%d\n",i);
    
    system("pause");
    return 0;
}
