#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
long long int gcd(long long int a,long long int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
long long int lcm(long long int a,long long int b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    long long int a,b;
    while(scanf("%lld%lld",&a,&b) && (a||b))printf("%lld\n",lcm(a,b)/a*lcm(a,b)/b);
    return 0;
}
