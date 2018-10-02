#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
unsigned long long pri[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
unsigned long long ans[105],flag;
unsigned long long prime[105],cnt[105],all[105];
unsigned long long gcd(unsigned long long a,unsigned long long b)
{
	while(b)
	{
		unsigned long long c=a%b;
		a=b;
		b=c;
	}
	return a;
}
unsigned long long multi(unsigned long long a,unsigned long long b,unsigned long long n)
{
	unsigned long long tmp=0;
	b=(b%n+n)%n;
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
unsigned long long multimod(unsigned long long a,unsigned long long m,unsigned long long n)
{
	unsigned long long tmp=1;
	a%=n;
	while(m)
	{
		if(m&1) tmp=multi(tmp,a,n);
		a=multi(a,a,n);
		m>>=1;
	}
	return tmp;
}
bool Miller_Rabin(unsigned long long n)
{
	if(n<2)
		return false;
	if(n==2)
		return true;
	if(!(n&1))
		return false;
	unsigned long long k=0,i,j,m,a;
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
unsigned long long pollard_rho(unsigned long long c,unsigned long long n)
{
	unsigned long long i,x,y,k,d;
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
void rho(unsigned long long n)
{
    if(n==1)return;
	if(Miller_Rabin(n))
    {
        ans[flag]=n;
        flag++;
        return;
    }
	unsigned long long t=n;
	while(t>=n)
		t=pollard_rho(rand()%(n-1)+1,n);
	rho(t);
	rho(n/t);
	return;
}
int main()
{
    unsigned long long a,b,num,i,n,j,aa,bb,mina,minb,mmin;
    while(scanf("%llu%llu",&a,&b)!=EOF)
    {
        if(a==b)
        {
            printf("%llu %llu\n",a,b);
            continue;
        }
        flag=0;
        rho(b/a);
        sort(ans,ans+flag);
        all[0]=prime[0]=ans[0];
        cnt[0]=1;
        num=1;
        for(i=1;i<flag;i++)
        {
            if(ans[i]==ans[i-1])
            {
                cnt[num-1]++;
                all[num-1]*=prime[num-1];
            }
            else
            {
                prime[num++]=ans[i];
                all[num-1]=prime[num-1];
                cnt[num-1]=1;
            }
        }
        mmin=((1LL<<63)-1);
        //for(i=0;i<num;i++)cout<<prime[i]<<' '<<all[i]<<endl;
        n=(1<<num);
        for(i=0;i<n;i++)
        {
            aa=bb=1;
            for(j=0;j<num;j++)
            {
                if(i&(1<<j))aa*=all[j];
                else bb*=all[j];
            }
            if(aa+bb<mmin)
            {
                mmin=aa+bb;
                mina=aa;
                minb=bb;
            }
        }
        if(mina>minb)swap(mina,minb);
        printf("%llu %llu\n",mina*a,minb*a);
    }
    return 0;
}
