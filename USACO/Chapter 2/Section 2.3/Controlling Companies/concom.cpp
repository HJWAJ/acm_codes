/*
ID: hjw00002
PROG: concom
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int n,m,s,t,val;
int dp[105][105],cnt[105];
bool bo[105],have[105];
void dfs(int num)
{
    int i;
    if(bo[num])return ;
    bo[num]=1;
    for(i=n;i>0;i--)
    {
        cnt[i]+=dp[num][i];
        if(cnt[i]>50)
        {
            have[i]=1;
            dfs(i);
        }
    }
}
int main()
{
    freopen("concom.in","r",stdin);
    freopen("concom.out","w",stdout);
    int i,j;
    memset(dp,0,sizeof(dp));
    scanf("%d",&m);
    n=0;
    while(m--)
    {
        scanf("%d%d%d",&s,&t,&val);
        if(s>n)n=s;
        if(t>n)n=t;
        dp[s][t]=val;
    }
    for(i=1;i<=n;i++)
    {
        memset(have,0,sizeof(have));
        memset(cnt,0,sizeof(cnt));
        memset(bo,0,sizeof(bo));
        dfs(i);
        for(j=1;j<=n;j++)
            if(have[j] && i!=j)printf("%d %d\n",i,j);
    }
    return 0;
}
