#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int n,i,a,b,sum=0,max=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&a,&b);
        sum-=a;
        sum+=b;
        if(sum>max)max=sum;
    }
    printf("%d\n",max);
    return 0;
}
