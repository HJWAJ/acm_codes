#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int a[105];
int main()
{
    int n,sum=0,cnt=0,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
        sum+=a[i];
    }
    if(sum&1)
    {
        for(i=0;i<n;i++)
            if(a[i]&1)cnt++;
    }
    else
    {
        for(i=0;i<n;i++)
            if(a[i]&1)cnt++;
        cnt=n-cnt;
    }
    printf("%d\n",cnt);
    return 0;
}
