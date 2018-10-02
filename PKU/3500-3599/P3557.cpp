#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
double dp[30];
int c[30][30];
void cc()
{
    for(int i=0;i<30;i++)
        c[i][0]=c[i][i]=1;
    for(int i=2;i<30;i++)
        for(int j=1;j<i;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
}
int main()
{
    cc();
    int n,i,j;
    double p,ans;
    while(scanf("%d%lf",&n,&p)!=EOF)
    {
        dp[1]=1.0;
        for(i=2;i<=n;i++)
        {
            ans = 0.0;
            for(j=1;j<i;j++)
                ans+=c[i-1][j-1]*dp[j]*pow(1-p,double(j*(i-j)));
            dp[i]=1-ans;
        }
        printf("%.3lf\n",dp[n]);
    }
    return 0;
}
