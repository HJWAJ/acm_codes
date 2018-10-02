#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std;
const long long mod=10000000000LL;
long long multi(long long a,long long b,long long n)//乘法快速幂
{
	long long tmp=0;
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
long long multimod(long long a,long long m,long long n)//乘方快速幂
{
	long long tmp=1;
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
    long long i,sum=0;
    for(i=1;i<=1000;i++)
    {
        sum+=multimod(i,i,mod);
        sum%=mod;
    }
    printf("%lld\n",sum);
    return 0;
}
