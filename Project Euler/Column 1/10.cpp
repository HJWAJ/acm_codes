#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
long long prime[100000];
bool bo[2000001];
long long prime_table()
{
    long long i,j,flag=0;
    memset(bo,0,sizeof(bo));
    bo[0]=bo[1]=1;
    for(i=2;i<=2000;i++)
        if(!bo[i])
        {
            j=i*i;
            for(;j<=2000000;j+=i)bo[j]=1;
        }
    for(i=0;i<=2000000;i++)
        if(!bo[i])prime[flag++]=i;
    return flag;
}
int main()
{
    long long i,sum=0;
    prime_table();
    for(i=0;prime[i]<=2000000;i++)sum+=prime[i];
    printf("%lld\n",sum);
    return 0;
}
