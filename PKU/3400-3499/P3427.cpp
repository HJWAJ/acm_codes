#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    int n,l,a[30005],i,max;
    while(scanf("%d%d",&n,&l)!=EOF)
    {
        max=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",a+i);
            a[i]%=l;
            if(a[i])a[i]=l-a[i];
            if(a[i]>max)max=a[i];
        }
        printf("%d\n",max);
    }
    return 0;
}
