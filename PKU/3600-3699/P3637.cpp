#include<iostream>
using namespace std;

int cmp(const void *p1,const void *p2)
{
    return *(int *)p2 - *(int *)p1;    
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,a[20000],i;
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        qsort(a,n,4,cmp);
        int sum=0;
        for(i=2;i<n;i+=3)sum+=a[i];
        printf("%d\n",sum);
    }    
    
    system("pause");
    return 0;
}
