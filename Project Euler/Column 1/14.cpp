/*

I tried dynamic programming but something was wrong and I don't know y.

Finally I used brute force and found it's also fast.

*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int dp[1000005];
int dfs(long long n)
{
    if(dp[n])return dp[n];
    if(n==1)return dp[n]=1;
    if((n&1LL) && n<=1000000)return dp[n]=dfs(n*3+1)+1;
    if(n&1LL)return dfs(n*3+1)+1;
    if(!(n&1LL) && n<=1000000)return dp[n]=dfs(n/2)+1;
    return dfs(n/2)+1;
}
int main()
{
    freopen("2.txt","w",stdout);
    int max=-1,i,maxi,cnt;
    long long ii;
    memset(dp,0,sizeof(dp));
    for(i=1;i<=1000000;i++)
    {
        cout<<i<<endl;
        /*dp[i]=dfs(i);
        if(dp[i]>max)
        {
            max=dp[i];
            maxi=i;
        }*/
        ii=i;
        cnt=0;
        while(ii!=1)
        {
            if(ii&1LL)ii=ii*3+1;
            else ii/=2;
            cnt++;
        }
        if(cnt>max)
        {
            max=cnt;
            maxi=i;
        }
    }
    printf("%d\n",maxi);
    return 0;
}
