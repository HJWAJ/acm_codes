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
int prime[2000000];
bool bo[10000005];
int ten[]={1,10,100,1000,10000,100000,10000000,10000000,100000000};
int prime_table()
{
    int i,j,flag=0;
    memset(bo,0,sizeof(bo));
    bo[0]=bo[1]=1;
    for(i=2;i<=5000;i++)
        if(!bo[i])
        {
            j=i*i;
            for(;j<=10000000;j+=i)bo[j]=1;
        }
    for(i=0;i<=10000000;i++)
        if(!bo[i])prime[flag++]=i;
    return flag;
}
bool is1(int n)
{
    while(n)
    {
        if(bo[n])return 0;
        n/=10;
    }
    return 1;
}
bool is2(int n)
{
    int nn=n,len=0;
    while(n)
    {
        n/=10;
        len++;
    }
    while(nn)
    {
        if(bo[nn])return 0;
        nn%=ten[len-1];
        len--;
    }
    return 1;
}
int main()
{
    int flag=prime_table(),i,cnt=0,sum=0;
    for(i=4;i<flag;i++)
        if(is1(prime[i]) && is2(prime[i]))
        {
            sum+=prime[i];
            cnt++;
            if(cnt==11)break;
        }
    printf("%d\n",sum);
    return 0;
}
