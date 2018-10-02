#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
const long long mod=10000000000LL;
int main()
{
    long long a=1LL;
    for(int i=0;i<7830457;i++)
    {
        a<<=1;
        if(a>mod)a%=mod;
    }
    a*=28433;
    a+=1;
    a%=mod;
    cout<<a<<endl;
    return 0;
}
