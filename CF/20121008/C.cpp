#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
using namespace std;
__int64 a[100005];
__int64 dis[100005];
__int64 dist(__int64 i,__int64 st)
{
    return a[i]*(i-st+1)-(dis[i+1]-dis[st]);
}
int main()
{
    __int64 n,i,k,st,tmp,cnt,max=1,maxans;
    scanf("%I64d%I64d",&n,&k);
    for(i=0;i<n;i++)scanf("%I64d",a+i);
    sort(a,a+n);
    dis[0]=0;
    for(i=0;i<n;i++)
    {
        dis[i+1]=dis[i]+a[i];
    }
    for(i=0,st=0;i<n;i++)
    {
        if(dist(i,st)<=k)
        {
            if(i-st+1>max)
            {
                max=i-st+1;
                maxans=a[i];
            }
        }
        else
        {
            while(dist(i,st)>k)st++;
            if(i-st+1>max)
            {
                max=i-st+1;
                maxans=a[i];
            }
        }
    }
    printf("%I64d %I64d\n",max,maxans);
	return 0;
}
