#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<fstream>
using namespace std;
const __int64 mod=1000000007LL;
__int64 solve(char s[],__int64 k)
{
    __int64 len=strlen(s);
    if(len<2)return 0;
    __int64 sub=0,sum=0,i;
    if(s[0]<'7')sub+=2;
    if(s[0]<'4')sub+=2;
    if(s[len-1]<'7')sub+=2;
    if(s[len-1]<'4')sub+=2;
    if(s[0]>='4' && s[0]<'7')
    {
        if(s[len-1]<'4')sum=2;
        else if(s[len-1]>='4' && s[len-1]<'7') sum=1;
    }
    else if(s[0]<'4')
    {
        if(s[len-1]<'4')sum=4;
        else if(s[len-1]>='4' && s[len-1]<'7')sum=2;
    }
    k=(k<len-2)?k:(len-2);
    for(i=0;i<k;i++)
    {
        sum+=(len-1-i)*4;
        sum%=mod;
        sum+=mod;
    }
    sum-=2*sub;
    for(i=0;i<len-3;i++)
    {
        sum*=10;
        sum%=mod;
    }
    return sum;
}
int main()
{
    __int64 t,k,ans;
    char a[1005],b[1005];
    scanf("%I64d%I64d",&t,&k);
    while(t--)
    {
        scanf("%s%s",&a,&b);
        ans=(solve(b,k)+mod-solve(a,k))%mod;
        printf("%I64d %I64d %I64d\n",solve(b,k),solve(a,k),ans);
    }

    return 0;
}
