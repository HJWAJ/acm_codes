//f(n,k)=k! * ( (k+1)^(n-k) - k^(n-k) ) % mod
#include<iostream>
#include<cstdio>
#include<cstring>
const __int64 mod=20100713LL;
using namespace std;

__int64 jiecheng[1000005];

void solve()
{
    jiecheng[0]=jiecheng[1]=1;
    int i; 
    for(i=2;i<=1000000;i++)
        jiecheng[i]=jiecheng[i-1]*i%mod;
}

__int64 multimod(__int64 x,__int64 n,__int64 mod)
{
    __int64 tmp=x,res=1LL;
    while(n)
    {
        if(n&1LL)
        {
            res*=tmp;
            res%=mod;
        }
        tmp*=tmp;
        tmp%=mod;
        n>>=1LL;
    }
    return res;
}

int main()
{
    __int64 t,n,k,i,j;
    __int64 ans1,ans2,ans;
    solve();
    scanf("%I64d",&t);
    while(t--)
    {
        scanf("%I64d%I64d",&n,&k);
        if(k==0)
        {
            printf("1\n");
            continue;        
        }
        ans1=ans2=jiecheng[k];
        ans1*=multimod(k+1,n-k,mod);
        ans1%=mod;
        ans1+=mod;
        ans2*=multimod(k,n-k,mod);
        ans2%=mod;
        ans=(ans1-ans2)%mod;
        printf("%I64d\n",ans);
    }
    
    return 0;
}
