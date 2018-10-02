#include<iostream>
#include<cstdio>
#include<cstring>
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
    long long int t,n,a[1005],i,_lcm;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        _lcm=1;
        for(i=0;i<n;i++)scanf("%lld",a+i);
        for(i=0;i<n;i++)
        {
            _lcm=lcm(_lcm,a[i]);
            if(_lcm>1000000000)
            {
                printf("More than a billion.\n");
                goto label;                   
            }
        }          
        printf("%lld\n",_lcm);
        label:;
    }    
    
    return 0;
}
