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
__int64 mod=1000000007LL;
__int64 multi(__int64 a,__int64 b,__int64 n)
{
	__int64 tmp=0;
	while(b){
		if(b&1){
			tmp+=a;
			if(tmp>=n)
				tmp-=n;
		}
		a<<=1;
		if(a>=n)a-=n;
		b>>=1;
	}
	return tmp;
}
__int64 multimod(__int64 a,__int64 m,__int64 n)
{
	__int64 tmp=1;
	a%=n;
	while(m)
	{
		if(m&1) tmp=multi(tmp,a,n);
		a=multi(a,a,n);
		m>>=1;
	}
	return tmp;
}
int main()
{
    __int64 n;
    scanf("%I64d",&n);
    if(n==0)puts("1");
    else printf("%I64d\n",multi(multimod(2,n-1,mod),(multimod(2,n,mod)+1)%mod,mod));
    return 0;
}
