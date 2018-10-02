#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<vector>
using namespace std;
int main()
{
    int a[15],i,t,n;
    double b[15];
    a[0]=1;b[1]=0;
    for(i=1;i<=12;i++)a[i]=a[i-1]*i;
    for(i=2;i<=12;i+=2)
    {
        b[i]=b[i-1]+1.0/a[i];
        b[i+1]=b[i]-1.0/a[i+1];
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n<=13)printf("%.4lf\n",b[n]);
        else printf("%.4lf\n",b[13]);
    }
    return 0;
}
