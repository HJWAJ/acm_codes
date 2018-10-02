#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int a[10005];
int main()
{
    int n,i,l,r;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)scanf("%d",a+i);
        sort(a,a+n);
        l=0;r=n-1;
        while(l<r-1)
        {
            printf("%d ",a[r]);
            r--;
            printf("%d ",a[l]);
            l++;
        }
        if(l==r-1)printf("%d %d\n",a[r],a[l]);
        else printf("%d\n",a[r]);
    }
    return 0;
}
