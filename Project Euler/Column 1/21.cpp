#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
long long f(long long n)
{
    long long nn=sqrt(n),res=0,i;
    for(i=2;i<nn;i++)
        if(n%i==0)
        {
            res+=i;
            res+=(n/i);
        }
    if(nn*nn==n)res+=nn;
    return res+1;
}
int main()
{
    long long i,cnt=0;
    for(i=3;i<=10000;i++)
        if(f(f(i))==i && f(i)!=i)cnt+=i;
    printf("%lld\n",cnt);
    return 0;
}
