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
int prime[50000000];
bool bo[1000000001];
int prime_table()
{
    int i,j,flag=0;
    memset(bo,0,sizeof(bo));
    bo[0]=bo[1]=1;
    for(i=2;i<=32000;i++)
        if(!bo[i])
        {
            j=i*i;
            for(;j>=0 && j<=1000000000;j+=i)bo[j]=1;
        }
    for(i=0;i<=1000000000;i++)
        if(!bo[i])prime[flag++]=i;
    return flag;
}
char s[10];
long long mod,ans;
int main()
{
    freopen("1.txt","w",stdout);
    prime_table();
    //cout<<"***"<<endl;//打10^9的素数表需要约1分钟
    long long a;
    int cnt=0,i;
    for(i=0;1.0/prime[i]>=1.38E-9;i++);
    for(;1.0/prime[i]>1.37E-9;i++)
    {
        mod=prime[i];
        if(mod*56789%100000!=99999)continue;//1/mod=...56789，故1/mod=...56789/...99999，交叉相乘得mod*56789%100000=99999
        //cout<<mod<<endl;//符合1/mod=给出循环节的数，能出此类循环节的一定是素数
        cnt=0;
        a=1;
        ans=0;
        while(cnt!=mod)//暴力求出整个循环节，对每个mod需要约10s
        {
            if(cnt>mod-7)
            {
                s[cnt-(mod-6)]=a/mod+'0';
            }
            ans+=(a/mod);
            a%=mod;
            a*=10;
            cnt++;
        }
        s[6]='\0';
        //cout<<s<<endl;//验证尾数是否为56789
        printf("%lld\n",ans);//输出答案
    }
    return 0;
}


/*

output:

***
725509891
856789
3264794505
726509891
856789
3269294505
729809891
156789
3284144505

根据提示或通过验算，最后一个是正解。

*/
