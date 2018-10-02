#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int main() 
{
    long long map[]={0,45,9045,1395495,189414495,(long long)(2E31-1)};
    long long map2[]={0,9,189,2889,38889};
    long long N,n,k,x,l=0,number,result,digit,kk;
    double h;
    scanf("%lld",&N);
    while(N--) 
    {
        scanf("%lld",&l);
        for(k=1;l>map[k];k++);
        n=l-map[k-1];
        h=sqrt((double)2*n/k+(0.5+(double)map2[k-1]/k)*(0.5+(double)map2[k-1]/k))-0.5-(double)map2[k-1]/k;
        x=int(ceil(h));
        n=n-map2[k-1]*(x-1)-(x-1)*x/2*k;
        for(kk=1;map2[kk]<n;kk++);
        n-=map2[kk-1];
        number=(long long int)pow(10.0,double(kk-1))+(n-1)/kk;
        digit=kk-(n-1)%kk;
        result=number/(long long int)(pow(10.0,double(digit-1)))%10;
        printf("%lld\n",result);
    }
    system("pause");
    return 0;
}
