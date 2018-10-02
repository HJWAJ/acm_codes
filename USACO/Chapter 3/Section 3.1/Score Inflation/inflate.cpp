/*
ID: hjw00002
PROG: inflate
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int dp[10005];
int main()
{
    freopen("inflate.in","r",stdin);
    freopen("inflate.out","w",stdout);
    int m,n,i,j,cost,weight;
    scanf("%d%d",&m,&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&weight,&cost);
        for(j=cost;j<=m;j++)
            dp[j]=max(dp[j],dp[j-cost]+weight);
    }
    printf("%d\n",dp[m]);
    return 0;
}
