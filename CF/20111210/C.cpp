#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std;
int a[100010];
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",a+i);
    if(n==1 && a[0]==1)
    {
        puts("2");
        return 0;
    }
    sort(a,a+n);
    for(i=0;i<n;i++)
        if(a[i]!=1)break;
    if(i==n)
    {
        printf("1");
        for(i=1;i<n-1;i++)printf(" 1");
        puts(" 2");
    }
    else
    {
        printf("1");
        for(i=1;i<n;i++)printf(" %d",a[i-1]);
        puts("");
    }
    return 0;
}
