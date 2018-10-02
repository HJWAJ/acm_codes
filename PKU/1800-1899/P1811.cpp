#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int pri[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
__int64 gcd(__int64 a,__int64 b)
{
	while(b)
	{
		__int64 c=a%b;
		a=b;
		b=c;
	}
	return a;
}
__int64 product_mod(__int64 a,__int64 b,__int64 n){
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
__int64 power_mod(__int64 a,__int64 m,__int64 n)
{
	__int64 tmp=1;
	a%=n;
	while(m)
	{
		if(m&1) tmp=product_mod(tmp,a,n);
		a=product_mod(a,a,n);
		m>>=1;
	}
	return tmp;
}
bool Miller_Rabin(__int64 n)
{
	if(n<2)
		return false;
	if(n==2)
		return true;
	if(!(n&1))
		return false;
	__int64 k=0,i,j,m,a;
	m=n-1;
	while(!(m&1)) m>>=1,k++;
	for(i=0;i<10;i++)
	{
		if(pri[i]>=n)
			return true;
		a=power_mod(pri[i],m,n);
		if(a==1) continue;
		for(j=0;j<k;j++)
		{
			if(a==n-1)
				break;
			a=product_mod(a,a,n);
		}
		if(j==k)
			return false;
	}
	return true;
}
__int64 pollard_rho(__int64 c,__int64 n)
{
	__int64 i,x,y,k,d;
	i=1;
	x=y=rand()%n;
	k=2;
	do{
		i++;
		d=gcd(n+y-x,n);
		if(d>1&&d<n)
			return d;
		if(i==k) y=x,k<<=1;
		x=(product_mod(x,x,n)+n-c)%n;
	}while(y!=x);
	return n;
}
__int64 rho(__int64 n)
{
	if(Miller_Rabin(n))
		return n;
	__int64 t=n;
	while(t>=n)
		t=pollard_rho(rand()%(n-1)+1,n);
	__int64 a=rho(t);
	__int64 b=rho(n/t);
	return a<b?a:b;
}
int main()
{
    int t;
    __int64 n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        if(Miller_Rabin(n))puts("Prime");
        else printf("%I64d\n",rho(n));
    }
    return 0;
}
