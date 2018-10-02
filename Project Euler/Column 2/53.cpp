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
int c[105][105];
int dp(int n,int m)
{
    if(c[n][m]!=-1)return c[n][m];
    if(m>n)return c[n][m]=0;
    if(m==n || m==0)return c[n][m]=1;
    int tmp=dp(n-1,m)+dp(n-1,m-1);
    if(tmp>1000000)return c[n][m]=1000001;
    return c[n][m]=tmp;
}
int main()
{
    int cnt=0,i,j;
    memset(c,-1,sizeof(c));
    for(i=1;i<101;i++)
        for(j=1;j<101;j++)
            if(dp(i,j)>1000000)cnt++;
    printf("%d\n",cnt);
    return 0;
}
