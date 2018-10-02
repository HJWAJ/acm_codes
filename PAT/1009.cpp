#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
double ans[2005],a[1005],b[1005];
int main()
{
    int n,m,i,j,cnt=0,exp;
    double coef;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%lf",&exp,&coef);
        a[exp]=coef;
    }
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%lf",&exp,&coef);
        b[exp]=coef;
    }
    for(i=0;i<=1000;i++)
        for(j=0;j<=1000;j++)
            ans[i+j]+=a[i]*b[j];
    for(i=0;i<=2000;i++)
        if(ans[i]!=0)
            cnt++;
    printf("%d",cnt);
    for(i=2000;i>=0;i--)
        if(ans[i]!=0)
            printf(" %d %.1lf",i,ans[i]);
    puts("");
    return 0;
}
