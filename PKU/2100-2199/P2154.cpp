#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int divi[100005];
int prime[50000];
bool bo[50001];
int p[100005],a[100005];
int prime_table()
{
    int i,j,flag=0;
    memset(bo,0,sizeof(bo));
    bo[0]=bo[1]=1;
    for(i=2;i<=50000;i++)
        if(!bo[i])
        {
            prime[flag++]=i;
            j=i+i;
            for(;j<=50000;j+=i)bo[j]=1;
        }
    return flag;
}
int divided(int n)
{
    int sq=(int)(sqrt(double(n)));
    int flag=0,num=0;
    while(1)
    {
        if(n==1)break;
        if(prime[flag]>sq)
        {
            p[num]=n;
            a[num++]=1;
            break;
        }
        if(n%prime[flag]!=0)
        {
            flag++;
            continue;
        }
        p[num]=prime[flag];
        a[num++]=1;
        n/=prime[flag];
        while(n%prime[flag]==0)
        {
            n/=prime[flag];
            a[num-1]++;
        }
        flag++;
    }
    return num;
}
int divide(int n)
{
    int i,flag=0;
    for(i=1;i*i<n;i++)
    {
        if(n%i==0)
        {
            divi[flag++]=i;
            divi[flag++]=n/i;
        }
    }
    if(i*i==n)divi[flag++]=i;
    return flag;
}
int eular(int n)
{
    if(n==1)return 1;
    int flag=divided(n),i;
    //for(i=0;i<flag;i++)cout<<p[i]<<' '<<a[i]<<endl;
    for(i=0;i<flag;i++)
    {
        n/=p[i];
        n*=(p[i]-1);
    }
    return n;
}
int multi(int a,int b,int n)//乘法快速幂
{
	int tmp=0;
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
int multimod(int a,int m,int n)//乘方快速幂
{
	int tmp=1;
	a%=n;
	while(m)
	{
		if(m&1)tmp=multi(tmp,a,n);
		a=multi(a,a,n);
		m>>=1;
	}
	return tmp;
}
int main()
{
    int t,n,mod,res,flag,i;
    prime_table();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&mod);
        res=0;
        flag=divide(n);
        for(i=0;i<flag;i++)res+=multi( multimod(n%mod,divi[i]-1,mod), eular(n/divi[i])%mod, mod);
        res%=mod;
        printf("%d\n",res);
    }
	return 0;
}
