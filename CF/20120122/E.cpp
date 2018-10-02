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
using namespace std;
const __int64 mod=1000000007LL;
__int64 a[100005];
__int64 cnt[100005];
int bo[100005];
bool islucky(__int64 n)
{
    while(n)
    {
        if(n%10!=4 && n%10!=7)return 0;
        n/=10;
    }
    return 1;
}
int main()
{
    int n,k,i,flag=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)scanf("%I64d",a+i);
    memset(cnt,0,sizeof(cnt));
    memset(bo,0,sizeof(bo));
    sort(a,a+n);
    bo[0]=1;
    for(i=1;i<n;i++)
    {
        if(a[flag]!=a[i] || (a[flag]==a[i] && !islucky(a[i])))
        {
            flag++;
            a[flag]=a[i];
        }
        bo[flag]++;
    }
    flag++;
    if(flag<k)
    {
        puts("0");
        return 0;
    }
    cnt[0]=1;
    for(i=0;i<k;i++)
    {
        cnt[0]*=bo[i];
        cnt[0]%=mod;
    }
    for(i=1;i<=flag-k;i++)
    {
        cnt[i]=cnt[i-1]%mod;
        cnt[i]+=(cnt[i-1]*bo[i+k-1]%mod*k%mod);
        cnt[i]%=mod;
    }
    printf("%I64d\n",cnt[flag-k]);
    return 0;
}
