#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<queue>
#include<string>
#include<vector>
#include<windows.h>
using namespace std;
long long pri[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};//用小素数表做随机种子可避免第一类卡米歇尔数的误判
long long ans[100005],flag;//ans数组记录分解质因数的结果，flag记录质因数的个数，******相同的质因数不合并！
long long gcd(long long a,long long b)//非递归，递归的对大数易爆栈
{
	while(b)
	{
		long long c=a%b;
		a=b;
		b=c;
	}
	return a;
}
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
bool Miller_Rabin(long long n)//大数判断
{
	if(n<2)
		return false;
	if(n==2)
		return true;
	if(!(n&1))
		return false;
	long long k=0,i,j,m,a;
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
int main()
{
    int pnum=3,allnum=5;
    long long step=4,base=9;
    while(pnum*10>=allnum)
    {
        allnum+=4;
        for(int i=0;i<4;i++)
        {
            base+=step;
            if(Miller_Rabin(base))pnum++;//打了10^9的素数表还爆，Miller_Rabin居然只要3秒不到，太神奇了 
        }
        step+=2;
    }
    printf("%d\n",step-1);//上面+2了，这里应该是-1而不是+1，WA了一次 
    return 0;
}
