#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
long long a[10005],sum;
int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)scanf("%lld",a+i);
        sort(a,a+n);
        sum=0;
        for(i=0;i<n-1;i++)sum+=(i+1)*(n-i-1)*(a[i+1]-a[i]);
        sum*=2;
        printf("%lld\n",sum);
    }
    return 0;
}
