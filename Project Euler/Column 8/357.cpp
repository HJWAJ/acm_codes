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
#include<ctime>
using namespace std;
#define nmax 100000000
int prime[10000000],factor[10000000],cfactor[10000000],divisor[10000000];
bool flag[nmax];
int plen,flen,dlen;
void init()
{
    memset(flag,0,sizeof(flag));
    int i,j;
    for(i=2,plen=0;i<nmax;i++)
    {
        if(!flag[i])prime[plen++]=i;
        for(j=0;j<plen && i*prime[j]<nmax;j++)
        {
            flag[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
void findFactor(int n)
{
    int i,te,cnt;
    te=(int)(sqrt(n));
    for(i=0,flen=0;i<plen && prime[i]<=te;i++)
    {
        if(n%prime[i]==0)
        {
            cnt=0;
            while(n%prime[i]==0)
            {
                cnt++;
                n/=prime[i];
            }
            factor[flen]=prime[i];
            cfactor[flen]=cnt;
            flen++;
        }
    }
    if(n>1)
    {
        factor[flen]=n;
        cfactor[flen]=1;
        flen++;
    }
}
void dfs(int k,int now)
{
    if(k==flen)
    {
        divisor[dlen++]=now;
        return;
    }
    int i;
    for(i=0;i<cfactor[k];i++)
    {
        now=now*factor[k];
        dfs(k+1,now);
    }
    for(i=0;i<cfactor[k];i++)now=now/factor[k];
    dfs(k+1,now);
}
int cmp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    init();
    int i,j;
    long long sum=0;
    for(i=1;i<=100000000;i++)
    {
        findFactor(i);
        dlen=0;
        dfs(0,1);
        for(j=0;j<dlen;j++)
            if(flag[divisor[j]+i/divisor[j]])
                break;
        if(j==dlen)sum+=i;
        //if(i%100000==0)cout<<i/100000<<endl;
    }
    printf("%lld\n",sum);
    return 0;
}
/**
 *
 * Brute Force. Use DFS but not FOR to calc divisors.
 * Ans: 1739023853137
 * Process returned 0 (0x0)   execution time : 899.400 s
 * Press any key to continue.
 *
 */
