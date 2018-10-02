/*
ID: hjw00002
PROG: fracdec
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int prime[200000];
bool bo[1000001];
int prime_table()
{
    int i,j,flag=0;
    memset(bo,0,sizeof(bo));
    bo[0]=bo[1]=1;
    for(i=2;i<=1000;i++)
        if(!bo[i])
        {
            j=i*i;
            for(;j<=1000000;j+=i)bo[j]=1;
        }
    for(i=0;i<=1000000;i++)
        if(!bo[i])prime[flag++]=i;
    return flag;
}
int divide(int n,int p[],int a[])
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
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int expmod(int m)
{
    int cnt=1,ans=10;
    while(ans%m!=1)
    {
        ans*=10;
        ans%=m;
        cnt++;
    }
    return cnt;
}
int multimod(int a,int m)
{
	int tmp=1;
	while(m)
	{
		if(m&1)tmp=tmp*a;
		a=a*a;
		m>>=1;
	}
	return tmp;
}
char s[1000005];
int main()
{
    freopen("fracdec.in","r",stdin);
    freopen("fracdec.out","w",stdout);
    int a,b,d,divi[105],exp[105],num,two,five,len,m,k,i,l=0;
    prime_table();
    scanf("%d%d",&a,&b);
    d=gcd(a,b);
    a/=d;
    b/=d;
    num=divide(b,divi,exp);
    //cout<<num<<' '<<b<<endl;
    //for(i=0;i<num;i++)cout<<divi[i]<<' '<<exp[i]<<endl;
    if(divi[0]==2)two=exp[0];
    else two=0;
    if(divi[0]==5)five=exp[0];
    else if(divi[1]==5)five=exp[1];
    else if(divi[2]==5)five=exp[2];
    else five=0;
    len=max(two,five);
    //cout<<two<<' '<<five<<endl;
    sprintf(s+l,"%d",a/b);
    l=strlen(s);
    //puts(s);
    a%=b;
    sprintf(s+l,".");
    l=strlen(s);
    for(i=0;i<len;i++)
    {
        sprintf(s+l,"%d",a*10/b);
        l=strlen(s);
        a=a*10%b;
    }
    //cout<<"aaa"<<endl;
    if(!a)
    {
        //puts(s);
        if(!len)
        {
            sprintf(s+l,"0");
            l=strlen(s);
            //puts(s);
        }
        else
        {
            sprintf(s+l,"");
            l=strlen(s);
        }
        //puts(s);
    }
    else
    {
        m=b/multimod(2,two)/multimod(5,five);
        k=expmod(m);
        //cout<<k<<endl;
        sprintf(s+l,"(");
        l=strlen(s);
        for(i=0;i<k;i++)
        {
            sprintf(s+l,"%d",a*10/b);
            l=strlen(s);
            a=a*10%b;
        }
        sprintf(s+l,")");
        l=strlen(s);
    }
    for(i=0;i<l;i++)
    {
        printf("%c",s[i]);
        if(i%76==75)puts("");
    }
    puts("");
    return 0;
}
