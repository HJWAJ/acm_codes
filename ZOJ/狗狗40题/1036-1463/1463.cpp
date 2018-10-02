#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<queue>
#include<string>
#include<vector>
using namespace std;
const int inf=1000;
char str[105],ss[105];
int state[105][105];
int dp[105][105];
void dfs(int i,int j)
{
    if(i>j)return;
    if(i==j)
    {
        if(str[i]=='['||str[i]==']')printf("[]");
        else printf("()");
    }
    else if(state[i][j]==-1)
    {
        printf("%c",str[i]);
        dfs(i+1,j-1);
        printf("%c",str[j]);
    }
    else
    {
        dfs(i,state[i][j]);
        dfs(state[i][j]+1,j);
    }
}
int main()
{
    //freopen("1.txt","w",stdout);
    int i,j,r,k,len,t;
    scanf("%d",&t);
    gets(ss);
    gets(ss);
    while(t--)
    {
        gets(str);
        if(t)gets(ss);
        len=strlen(str);
        if(len==0)
        {
            puts("");
            if(t)puts("");
            continue;
        }
        memset(dp,0,sizeof(dp));
        for(i=0;i<len;i++)dp[i][i]=1;
        for(r=1;r<len;r++)
            for(i=0;i<len-r;i++)
            {
                int j=r+i;
                dp[i][j]=inf;
                if((str[i]=='(' && str[j]==')') || (str[i]=='[' && str[j]==']'))
                {
                    if(dp[i][j]>dp[i+1][j-1])dp[i][j]=dp[i+1][j-1];
                    state[i][j]=-1;
                }
                for(k=i;k<j;k++)
                {
                    if(dp[i][j]>dp[i][k]+dp[k+1][j])
                    {
                        dp[i][j]=dp[i][k]+dp[k+1][j];
                        state[i][j]=k;
                    }
                }
            }
        dfs(0,len-1);
        puts("");
        if(t)puts("");
    }
}
