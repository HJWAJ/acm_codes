#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    long long int ans,t,l,r,n,tt=0;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&l,&r);
        tt++;
        ans=(l+r)*(r-l+1)/2;
        printf("Scenario #%lld:\n%lld\n\n",tt,ans);
    }    
    
    //system("pause");
    return 0;
}
