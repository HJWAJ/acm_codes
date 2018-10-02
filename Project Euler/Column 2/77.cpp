#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<vector>
using namespace std;
/**
 *
 * 打出素数表后dp，dp[i][j]表示把i分解为最大为prime[j]的和的方法数。
 *
 */
int prime[2000];
bool bo[10001];
int dp[10001][2001];
int prime_table()
{
    int i,j,flag=0;
    memset(bo,0,sizeof(bo));
    bo[0]=bo[1]=1;
    for(i=2;i<=100;i++)
        if(!bo[i])
        {
            j=i*i;
            for(;j<=10000;j+=i)bo[j]=1;
        }
    for(i=0;i<=10000;i++)
        if(!bo[i])prime[flag++]=i;
    return flag;
}
int main()
{
    int i,flag,j,cnt;
    prime_table();
    memset(dp,0,sizeof(dp));
    for(i=1;i<=10000;i++)
    {
        flag=0;
        if(!bo[i])
        {
            for(j=0;prime[j]!=i;j++);
            dp[i][j]=1;
        }
        while(prime[flag]<i)
        {
            for(j=0;j<=flag;j++)dp[i][flag]+=dp[i-prime[flag]][j];
            flag++;
        }
        cnt=0;
        for(j=0;j<flag;j++)cnt+=dp[i][j];
        if(cnt>5000)
        {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
