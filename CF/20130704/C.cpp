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
const __int64 mod=1000000007;
__int64 egcd(__int64 a,__int64 b,__int64 &x,__int64 &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    __int64 tmp=egcd(b,a%b,y,x);
    y-=(a/b)*x;
    return tmp;
}
__int64 ivt(__int64 a,__int64 m)
{
    __int64 x,y;
    egcd(a,m,x,y);
    return (x%m+m)%m;
}
__int64 multimod(__int64 a,__int64 n,__int64 m)
{
    __int64 res=1;
    while(n)
    {
        if(n&1LL)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}
__int64 calc(__int64 i,__int64 k,int len)
{
    __int64 res=multimod(2,len*k,mod);
    res=(res+mod-1)%mod;
    __int64 tmp=multimod(2,len,mod);
    tmp=(tmp+mod-1)%mod;
    res*=ivt(tmp,mod);
    res%=mod;
    res*=multimod(2,i,mod);
    res%=mod;
    return res;
}
char s[100005];
int main()
{
    int k,i,len;
    __int64 ans=0;
    scanf("%s%d",s,&k);
    len=strlen(s);
    for(i=0;i<len;i++)
        if(s[i]=='0' || s[i]=='5')
            ans+=calc(i,k,len);
    ans%=mod;
    printf("%I64d\n",ans);
    return 0;
}
