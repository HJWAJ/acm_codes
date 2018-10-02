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
#include<sstream>
using namespace std;
vector<int> v[1505];
int dp[1505][2];
int dfs(int root,int i)
{
    int tmp=0,k;
    if(dp[root][i]!=-1)return dp[root][i];
    if(v[root].size()==0)
    {
        if(i==0)return dp[root][i]=0;
        else return dp[root][i]=1;
    }
    if(i==0)
    {
        for(k=0;k<v[root].size();k++)
            tmp+=dfs(v[root][k],1);
        return dp[root][i]=tmp;
    }
    else
    {
        for(k=0;k<v[root].size();k++)
            tmp+=min(dfs(v[root][k],1),dfs(v[root][k],0));
        return dp[root][i]=tmp+1;
    }
}
int find(int root)
{
    return min(dfs(root,0),dfs(root,1));
}
int main()
{
    int n,i,j,id,num,a,root;
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++)
        {
            scanf("%d:(%d)",&id,&num);
            if(i==0)root=id;
            for(j=0;j<num;j++)
            {
                scanf("%d",&a);
                v[id].push_back(a);
            }
        }
        printf("%d\n",find(root));
        for(i=0;i<n;i++)v[i].clear();
    }
    return 0;
}
