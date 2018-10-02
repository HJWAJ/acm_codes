#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
    __int64 n,k,i,sum,tmp,sqr,a0,an;
    while(scanf("%I64d%I64d",&n,&k)!=EOF)
    {
        sum=0;
        if(n>k)sum+=((n-k)*k);
        sqr=(__int64)(sqrt(double(k)));
        tmp=k/sqr;
        for(i=sqr;i>1;i--)
        {
            a0=k/i;
            an=k/(i-1);
            if(a0>n)break;
            if(an>n)an=n;
            sum=sum+(k%(a0+1)+k%an)*(an-a0)/2;                  
        }
        for(i=1;i<=n && i<=tmp;i++)sum+=k%i;
        printf("%I64d\n",sum);
    }
    
    return 0;
}
