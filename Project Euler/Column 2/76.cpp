#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[105][105];
int dfs(int x,int y)
{
    if(dp[x][y]!=-1)return dp[x][y];
    if(x==0 || y==0)return dp[x][y]=0;
    if(x==1 || y==1)return dp[x][y]=1;
    if(x<y)return dp[x][y]=dfs(x,x);
    if(x==y)return dp[x][y]=dfs(x,y-1)+1;
    return dp[x][y]=dfs(x,y-1)+dfs(x-y,y);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    printf("%d\n",dfs(100,100)-1);
    return 0;
}
