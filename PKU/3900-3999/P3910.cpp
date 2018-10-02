#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
const int mod=1000000007;
int prime[30000];
bool bo[50005];
int prime_table()
{
    int i,j,flag=0;
    memset(bo,0,sizeof(bo));
    bo[0]=bo[1]=1;
    for(i=2;i<=50000;i++)
        if(!bo[i])
        {
            prime[flag++]=i;
            for(j=i+i;j<=50000;j+=i)bo[j]=1;
        }
    return flag;
}
int divided(int n,int p[],int a[])
{
    long long int sq=(long long int)(sqrt(double(n)));
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
int phi(int n,int p[],int a[])
{
    if(n==1)return 1;
    int flag=divided(n,p,a),i;
    for(i=0;i<flag;i++)
    {
        n/=p[i];
        n*=(p[i]-1);
    }
    return n;
}
int mult(int a,int b,int n)//³Ë·¨¿ìËÙÃÝ
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
int main()
{
    int n,a,ans,p[1005],div[1005];
    //puts("****");
    prime_table();
    //puts("****");
    while(scanf("%d",&n)!=EOF)
    {
        ans=1;
        while(n--)
        {
            scanf("%d",&a);
            ans=mult(ans,phi(a,p,div),mod);
        }
        printf("%d\n",ans);
    }
    return 0;
}
