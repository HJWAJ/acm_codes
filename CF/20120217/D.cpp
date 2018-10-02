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
#include<sstream>
using namespace std;
const __int64 mod=1000000007LL;
__int64 multimod(__int64 a,__int64 m,__int64 n)//³Ë·½¿ìËÙÃÝ
{
	__int64 tmp=1LL;
	a%=n;
	while(m)
	{
		if(m&1LL)tmp=tmp*a%n;
		a=a*a%n;
		m>>=1LL;
	}
	return tmp;
}
int main()
{
    __int64 n,m,k;
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    if(k>n || k==1)printf("%I64d\n",multimod(m,n,mod));
    else if(n&1)
    {
        if(n==k)printf("%I64d\n",multimod(m,n/2+1,mod));
        else if(k&1)printf("%I64d\n",m*m%mod);
        else printf("%I64d\n",m);
    }
    else
    {
        if(n==k)printf("%I64d\n",multimod(m,n/2,mod));
        else if(k&1)printf("%I64d\n",m*m%mod);
        else printf("%I64d\n",m);
    }
    return 0;
}
