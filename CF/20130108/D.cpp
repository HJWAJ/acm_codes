#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
__int64 a[100005];
char s[100005];
int main()
{
    int n,i;
    __int64 sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%I64d",a+i);
        sum+=a[i];
    }
    i=n-1;
    while(sum>a[0])
    {
        while(sum<a[i]*2)i--;
        sum-=a[i]*2;
        s[i]='-';
        i--;
    }
    for(i=0;i<n;i++)
        if(s[i]!='-')
            s[i]='+';
    puts(s);
    return 0;
}
