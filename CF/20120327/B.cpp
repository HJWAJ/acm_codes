#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
using namespace std;
typedef long long LL;
#define MAXN 205
double p[MAXN];
int a[MAXN];
double f[MAXN][MAXN][2*MAXN];
int main()
{
    int n,l,k,t,i,j,x;
    double res=0;
    scanf("%d%d%d",&n,&l,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%lf",p+i);
        p[i]/=100.0;
    }
    for(i=1;i<=n;i++)scanf("%d",a+i);
    f[0][0][k+200]=1.0;
    for(i=0;i<=n;i++)
        for(j=0;j<=i;j++)
            for(x=-200;x<=200;x++)
            {
                t=x+a[i]+200;
                if(t>400)t=400;
                if(t>=0)f[i+1][j+1][t]+=p[i]*f[i][j][x+200];
                f[i+1][j][x+200]+=(1.0-p[i])*f[i][j][x+200];
            }
    for(j=l;j<=n;j++)
        for(x=0;x<=200;x++)
            res+=f[n+1][j][x+200];
    printf("%.9lf\n",res);
    return 0;
}
