//9!=362880，362880*8=2903040<10000000（8位），所以只要测试到2903040

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std;
long long a[15],len;
long long f[]={1,1,2,6,24,120,720,5440,40320,362880};
long long getnum(long long n)
{
    int i=0;
    while(n)
    {
        a[i++]=n%10;
        n/=10;
    }
    return i;
}
int main()
{
    int i,j,sum=0,tmp;
    for(i=3;i<3000000;i++)
    {
        len=getnum(i);
        tmp=0;
        for(j=0;j<len;j++)tmp+=f[a[j]];
        if(tmp==i)sum+=i;
    }
    printf("%d\n",sum);
    return 0;
}
