#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
int a[100005];
int main()
{
    __int64 n,k,x,y,l,r;
    int i;
    scanf("%I64d%I64d",&n,&k);
    for(i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    x=k/n;
    if(k%n==0)x--;
    for(i=x-1;i>=0;i--)
        if(a[i]!=a[x])
            break;
    l=i+1;
    for(i=x+1;i<n;i++)
        if(a[i]!=a[x])
            break;
    r=i;
    k-=l*n;
    for(i=0;i<n;i++)
    {
        if(k>0)k-=(r-l);
        else break;
    }
    printf("%d %d\n",a[x],a[i-1]);
    return 0;
}
