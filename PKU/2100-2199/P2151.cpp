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
int m,n,num;
double p[1005][35];
double dp[1005][35][35];
double sum[1005][35];
double P,P1,P2;
int main()
{
    int i,j,k;
    while(scanf("%d%d%d",&n,&m,&num) && (m||n||num))
    {
        for(i=0;i<m;i++)
            for(j=1;j<=n;j++)
                scanf("%lf",&p[i][j]);
        for(i=0;i<m;i++)
        {
            dp[i][0][0]=1.0;
            for(k=1;k<=n;k++)dp[i][0][k]=0.0;
            for(j=1;j<=n;j++)dp[i][j][0]=dp[i][j-1][0]*(1-p[i][j]);
            for(j=1;j<=n;j++)
                for(k=1;k<=n;k++)
                    dp[i][j][k]=dp[i][j-1][k-1]*p[i][j]+dp[i][j-1][k]*(1-p[i][j]);
        }
        for(i=0;i<m;i++)
            for(j=0;j<=n;j++)
            {
                sum[i][j]=0.0;
                for(k=0;k<=j;k++)sum[i][j]+=dp[i][n][k];
            }
        P1=P2=1.0;
        for(i=0;i<m;i++)
        {
            P1*=(1-sum[i][0]);
            P2*=(sum[i][num-1]-sum[i][0]);
        }
        P=P1-P2;
        printf("%.3lf\n",P);
    }
    return 0;
}
