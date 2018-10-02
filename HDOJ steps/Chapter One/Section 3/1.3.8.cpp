#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int a[10005];
int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)scanf("%d",a+i);
        sort(a,a+n);
        printf("%d\n",a[n/2]);
    }
    return 0;
}
