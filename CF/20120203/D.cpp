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
double dp[1005][1005];
double dfs(int i,int j)
{
    double tmp;
    if(dp[i][j]!=-1.0)return dp[i][j];
    if(i==0)return dp[i][j]=0.0;
    if(j==0)return dp[i][j]=1.0;
    if(i==1 && j==1)return dp[i][j]=0.5;
    dp[i][j]=i*1.0/(i+j);
    tmp = j*1.0/(i+j) * (j-1)/(i+j-1);
    dp[i][j]+=tmp * i /(i+j-2) * dfs(i-1,j-2);
    dp[i][j]+= tmp * (j-2) / (i+j-2) * dfs(i,j-3);
    return  dp[i][j];
}
int main()
{
    int i,j;
    int w,b;
    scanf("%d%d",&w,&b);
    for(i=0;i<=w;i++)
        for(j=0;j<=b;j++)
            dp[i][j]=-1.0;
    printf("%.9lf\n",dfs(w,b));
    /*for(i=0;i<=w;i++)
        {for(j=0;j<=b;j++)
            printf("%.3lf ",dp[i][j]);
            printf("\n");}*/
    return 0;
}
