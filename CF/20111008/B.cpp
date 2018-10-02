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
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        for(j=0;j<2*n-2*i;j++)printf(" ");
        printf("0");
        for(j=1;j<=i;j++)printf(" %d",j);
        for(j=i-1;j>=0;j--)printf(" %d",j);
        puts("");
    }
    for(i=n-1;i>=0;i--)
    {
        for(j=0;j<2*n-2*i;j++)printf(" ");
        printf("0");
        for(j=1;j<=i;j++)printf(" %d",j);
        for(j=i-1;j>=0;j--)printf(" %d",j);
        puts("");
    }
    return 0;
}
