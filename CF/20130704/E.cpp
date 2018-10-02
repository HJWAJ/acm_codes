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
const __int64 mod=1000000007ll;
__int64 dp[1<<24];
__int64 val[1<<24];
bool can[1<<24];
__int64 a[24],c[3];
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%I64d",a+i);
    scanf("%d",&k);
    for(i=0;i<k;i++)scanf("%I64d",c+i);
    for(i=1;i<(1<<n);i++)
    {
        for(j=0;j<n;++j)
            if((i&(1<<j)))
            {
                val[i]=val[i^(1<<j)]+a[j];
                break;
            }
        if(val[i]==c[0] || val[i]==c[1])can[i]=1;
    }
    dp[0]=1;
    for(i=1;i<(1<<n);++i)
    {
        if(!can[i])
        {
            for(j=0;j<n;++j)
                if((i&(1<<j)))
                    dp[i]+=dp[i^(1<<j)];
            dp[i]%=mod;
        }
    }
    printf("%I64d\n",dp[(1<<n)-1]);
    return 0;
}
