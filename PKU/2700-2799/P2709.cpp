#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
    int n,a[15],i,num;
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<=n;i++)scanf("%d",a+i);
        while(a[n]--)
        {
            sort(a,a+n);
            a[0]++;
            a[1]++;
            a[2]++;
        }
        sort(a,a+n);
        num=a[n-1]/50;
        if(a[n-1]%50)num++;
        printf("%d\n",num);
    }
    return 0;
}
