#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<ctime>
using namespace std;
double a[1005];
int main()
{
    int exp,n,i,cnt=0;
    double coef;
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%lf",&exp,&coef);
        a[exp]+=coef;
    }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%lf",&exp,&coef);
        a[exp]+=coef;
    }
    for(i=1000;i>=0;i--)
        if(a[i]!=0)
            cnt++;
    printf("%d",cnt);
    for(i=1000;i>=0;i--)
        if(a[i]!=0)
            printf(" %d %.1lf",i,a[i]);
    puts("");
    return 0;
}
