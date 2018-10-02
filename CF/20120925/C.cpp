#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
#include<ctime>
using namespace std;
__int64 expi(__int64 a,__int64 n,__int64 mod)
{
    __int64 res=1LL;
    while(n)
    {
        if(n&1LL)res=res*a%mod;
        a=a*a%mod;
        n>>=1LL;
    }
    return res;
}
int main()
{
    __int64 n,mod;
    scanf("%I64d%I64d",&n,&mod);
    printf("%I64d\n",(expi(3,n,mod)-1+mod)%mod);
    return 0;
}