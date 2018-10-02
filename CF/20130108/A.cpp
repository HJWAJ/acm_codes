#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[55];
int main()
{
    int n,m,k,i,cnt=0;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    i=n-1;
    while(m>k)
    {
        m-=a[i]-1;
        i--;
        cnt++;
        if(i<0)break;
    }
    if(i<0)puts("-1");
    else printf("%d\n",cnt);
    return 0;
}
