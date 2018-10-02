#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int a[100005];
int id[100005];
int ans[100005];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int m,n,i,num,flag1,flag2,cnt=0,turn=0;
    scanf("%d",&m);
    for(i=0;i<m;i++)scanf("%d",a+i);
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",a+m+i);
    num=m+n;
    flag1=0;
    flag2=m;
    if(!a[flag1] || !a[flag2])
    {
        while(flag1<m && !a[flag1])
        {
            id[cnt++]=flag1;
            flag1++;
        }
        while(flag2<m+n && !a[flag2])
        {
            id[cnt++]=flag2;
            flag2++;
        }
    }
    while(flag1<m && flag2<n+m)
    {
        while(flag1<m  && a[flag1])
        {
            id[cnt++]=flag1;
            flag1++;
        }
        while(flag2<m+n && a[flag2])
        {
            id[cnt++]=flag2;
            flag2++;
        }
        while(flag1<m && !a[flag1])
        {
            id[cnt++]=flag1;
            flag1++;
        }
        while(flag2<m+n && !a[flag2])
        {
            id[cnt++]=flag2;
            flag2++;
        }
    }
    while(flag1<m)
    {
        id[cnt++]=flag1;
        flag1++;
    }
    while(flag2<m+n)
    {
        id[cnt++]=flag2;
        flag2++;
    }
    for(i=0;i<cnt-1;i++)printf("%d ",id[i]+1);
    printf("%d\n",id[i]+1);
    a[cnt]=0;
    id[cnt]=cnt;
    for(i=0;i<cnt;i++)
        if((a[id[i]]==0 && a[id[i+1]]==1) || (a[id[i]]==1 && a[id[i+1]]==0))
            turn++;
    printf("%d\n",turn);
    turn=0;
    for(i=0;i<cnt;i++)
        if((a[id[i]]==1 && a[id[i+1]]==0) || (a[id[i]]==0 && a[id[i+1]]==1))
            ans[turn++]=i;
    for(i=0;i<turn-1;i++)printf("%d ",ans[i]+1);
    printf("%d\n",ans[i]+1);
    return 0;
}
