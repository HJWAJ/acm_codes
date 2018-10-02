#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
#include<stack>
#include<sstream>
using namespace std;
int dp[10000005];
int gao(int n)
{
    int res=0,d;
    while(n)
    {
        d=n%10;
        res+=d*d;
        n/=10;
    }
    return res;
}
int dfs(int n)
{
    if(dp[n])return dp[n];
    if(n==89 || n==1)return dp[n]=n;
    return dp[n]=dfs(gao(n));
}
int main()
{
    int cnt=0;
    for(int i=1;i<=10000000;i++)
    {
        dfs(i);
        if(dp[i]==89)cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
