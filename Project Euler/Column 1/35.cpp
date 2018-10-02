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
int prime[200005];
bool bo[1000005];
int ten[]={1,10,100,1000,10000,100000,1000000};
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
bool is(int n)
{
    int p=n,len=0,i;
    while(p)
    {
        p/=10;
        len++;
    }
    p=n;
    for(i=0;i<len;i++)
    {
        p=p/10+p%10*ten[len-1];
        if(bo[p])return 0;
    }
    return 1;
}
int main()
{
    int flag=prime_table();
    int i,sum=0;
    for(i=0;i<flag;i++)
        if(is(prime[i]))
            sum++;
    printf("%d\n",sum);
    return 0;
}
