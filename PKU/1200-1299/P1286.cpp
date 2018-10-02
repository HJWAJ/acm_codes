#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<fstream>
using namespace std;
long long int gcd(long long int a,long long int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
long long int pow(long long int m,long long int n)
{
    long long int res=1;
    for(int i=0;i<n;i++)res*=m;
    return res;
}
int main()
{
    long long int c=3,s,cnt,res,i;
    while(scanf("%lld",&s) && s!=-1)
    {
        if(s==0)
        {
            puts("0");
            continue;
        }
        cnt=s*2;
        res=0;
        for(i=1;i<=s;i++)
        {
            res+=pow(c,gcd(s,i));
        }
        if(s&1)res+=(s*pow(c,s/2+1));
            else res+=(s/2*pow(c,s/2)+s/2*pow(c,s/2+1));
        res/=cnt;
        printf("%lld\n",res);
    }
    return 0;
}
