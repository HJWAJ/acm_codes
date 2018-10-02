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
//对于1要另外加特判，否则会出现RE！
__int64 pri[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};//用小素数表做随机种子可避免第一类卡米歇尔数的误判
__int64 ans[105],flag;//ans数组记录分解质因数的结果，flag记录质因数的个数，******相同的质因数不合并！
__int64 gcd(__int64 a,__int64 b)//非递归，递归的对大数易爆栈
{
	while(b)
	{
		__int64 c=a%b;
		a=b;
		b=c;
	}
	return a;
}
__int64 multi(__int64 a,__int64 b,__int64 n)//乘法快速幂
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
__int64 multimod(__int64 a,__int64 m,__int64 n)//乘方快速幂
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
bool Miller_Rabin(__int64 n)//大数判断
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
		a=multimod(pri[i],m,n);
		if(a==1) continue;
		for(j=0;j<k;j++)
		{
			if(a==n-1)
				break;
			a=multi(a,a,n);
		}
		if(j==k)
			return false;
	}
	return true;
}
__int64 pollard_rho(__int64 c,__int64 n)//寻找因数
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
		x=(multi(x,x,n)+n-c)%n;
	}while(y!=x);
	return n;
}
void rho(__int64 n)//递归分解
{
	if(Miller_Rabin(n))
    {
        ans[flag]=n;
        flag++;
        return;
    }
	__int64 t=n;
	while(t>=n)
		t=pollard_rho(rand()%(n-1)+1,n);//这一步的作用是随机取出一个因数，不一定是素数，也不确定大小
	rho(t);
	rho(n/t);
	return;
}
int main()
{
    __int64 n;
    flag=0;
    scanf("%I64d",&n);
    if(n==1)
    {
        puts("1");
        puts("0");
    }
    else if(Miller_Rabin(n))
    {
        puts("1");
        puts("0");
    }
    else
    {
        rho(n);
        if(flag>2)
        {
            puts("1");
            printf("%I64d\n",ans[0]*ans[1]);
        }
        else puts("2");
    }
    return 0;
}
