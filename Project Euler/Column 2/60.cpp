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
using namespace std;
__int64 prime[20000];
int flag;
int len[20000];
bool bo[40001];
int prime_table()
{
    int i,j,flag=0;
    memset(bo,0,sizeof(bo));
    bo[0]=bo[1]=1;
    for(i=2;i<=200;i++)
        if(!bo[i])
        {
            j=i*i;
            for(;j<=40000;j+=i)bo[j]=1;
        }
    for(i=0;i<=40000;i++)
        if(!bo[i])
        {
            if(i<10)len[flag]=1;
            else if(i<100)len[flag]=2;
            else if(i<1000)len[flag]=3;
            else if(i<10000)len[flag]=4;
            else if(i<100000)len[flag]=5;
            else len[flag]=6;
            prime[flag++]=i;
        }
    return flag;
}
__int64 pri[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
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
bool g[2005][2005];
__int64 ten[]={1,10,100,1000,10000,100000,1000000};
int save[10];
int dfs(int i,int cnt)
{
    int j,k;
    if(cnt==5)
    {
        int sum=0;
        for(i=0;i<5;i++)
        {
            cout<<prime[save[i]]<<endl;
            sum+=prime[save[i]];
        }
        return -1;
    }
    for(j=i+1;j<2000;j++)
        if(g[i][j])
        {
            for(k=0;k<cnt;k++)
                if(save[k]==j)break;
            if(k!=cnt)continue;
            for(k=0;k<cnt;k++)
                if(!g[j][save[k]])break;
            if(k!=cnt)continue;
            save[cnt]=j;
            if(dfs(j,cnt+1)==-1)return -1;
        }
}
int main()
{
    flag=prime_table();
    //cout<<flag<<endl;
    int i,j;
    __int64 tmp1,tmp2;
    memset(g,0,sizeof(g));
    for(i=0;i<2000;i++)
        {//cout<<i<<endl;
            for(j=0;j<i;j++)
            if(j!=i)
            {
                tmp1=prime[i]*ten[len[j]]+prime[j];
                tmp2=prime[j]*ten[len[i]]+prime[i];
                if(Miller_Rabin(tmp1) && Miller_Rabin(tmp2))
                {
                    g[i][j]=g[j][i]=1;
                    //cout<<j<<' ';
                    //for(k=0;k<10000000;k++);
                }
            }
        }//this takes too long time! I can make a 10000000 prime table to promote it.
    cout<<1<<endl;
    for(i=0;i<2000;i++)
    {
        save[0]=i;
        dfs(i,1);
    }
    return 0;
}
/*

13 5197 5701 6733 8389
26033

*/
