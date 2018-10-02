#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
using namespace std;
__int64 pri[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};//用小素数表做随机种子可避免第一类卡米歇尔数的误判
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
int getnum(char s[],int len)
{
    int res=0,i;
    for(i=0;i<len;i++)
    {
        res*=10;
        res+=(s[i]-'0');
    }
    return res;
}
int main()
{
    char s[9][15]={"1","12","123","1234","12345","123456","1234567","12345678","123456789"};
    char ss[9][15];
    int i;
    __int64 num,max=0;
    memcpy(ss,s,sizeof(s));
    for(i=1;i<10;i++)
    {
        do
        {
            next_permutation(s[i],s[i]+i);
            num=(__int64)getnum(s[i],i);
            if(Miller_Rabin(num) && num>max)max=num;
        }while(strcmp(s[i],ss[i])>0);
    }
    printf("%I64d\n",max);
    return 0;
}
