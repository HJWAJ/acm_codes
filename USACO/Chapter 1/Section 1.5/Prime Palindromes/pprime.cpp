/*
ID: hjw00002
PROG: pprime
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

int sushu[50000];
bool dabiao[200001];

void sushubiao()
{
    memset(sushu,0,sizeof(sushu));
    memset(dabiao,0,sizeof(dabiao));
    dabiao[0]=1;
    dabiao[1]=1;
    int num;
    int i,j;  
    for(i=2;i<=50000;i++)
        for(j=2;j<=50000/i;j++)
            dabiao[j*i]=1;  
    
    j=0;
    for(i=2;i<=50000;i++)if(dabiao[i]==0){sushu[j]=i;j++;}
}

bool isPrime(int n)
{
    int i;
    //*/
    if(n<=50000)
    {
        if(dabiao[n]==0)return 1;
        else return 0;             
    }
    //*/
    for(i=0;sushu[i]<=int(sqrt(double(n)));i++)
    {
        if(n%sushu[i]==0)return 0;                                   
    }  
    return 1;   
}

int main()
{
    freopen("pprime.in","r",stdin);
    freopen("pprime.out","w",stdout);
    sushubiao();
    int l,u,i,j,k,ii,prime[100005],num,flag=0;
    prime[flag++]=5;
    prime[flag++]=7;
    prime[flag++]=11;
    for(i=1;i<10;i++)
        for(j=0;j<10;j++)
        {
            num=i*101+j*10;
            if(isPrime(num))prime[flag++]=num;
        }
    for(i=1;i<10;i++)
        for(j=0;j<10;j++)
            for(k=0;k<10;k++)
            {
                num=i*10001+j*1010+k*100;
                if(isPrime(num))prime[flag++]=num;
            }
    for(i=1;i<10;i++)
        for(j=0;j<10;j++)
            for(k=0;k<10;k++)
                for(ii=0;ii<10;ii++)
                {
                    num=i*1000001+j*100010+k*10100+ii*1000;
                    if(isPrime(num))prime[flag++]=num;
                }
    scanf("%d%d",&l,&u);
    i=0;
    while(prime[i]<l)i++;
    while(prime[i]<=u && prime[i]>0)printf("%d\n",prime[i++]);
    
    //system("pause");
    return 0;
}
