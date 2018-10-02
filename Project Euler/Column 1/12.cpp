#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    long long n,i=1,j,nn,cnt;
    while(1)
    {
        n=i*(i+1)/2;
        i++;
        nn=sqrt(n);
        cnt=0;
        for(j=1;j<nn;j++)
            if(n%j==0)cnt+=2;
        if(nn*nn==n)cnt++;
        if(cnt>500)
        {
            printf("%lld\n",n);
            break;
        }
    }
    return 0;
}
