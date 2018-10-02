#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int x1,y1,x2,y2;
int x[1005],y[1005],r[1005];
bool inn(int x,int y,int x1,int y1,int r0)
{
    if( (x-x1) * (x-x1) + (y-y1) * (y-y1) <= r0*r0 )return 1;
    return 0;
}
int main()
{
    int n,i,j,cnt=0;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    if(x1>x2)swap(x1,x2);
    if(y1>y2)swap(y1,y2);
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d%d%d",x+i,y+i,r+i);
    for(i=x1;i<x2;i++)
    {
        for(j=0;j<n;j++)
            if(inn(i,y1,x[j],y[j],r[j]))
                break;
        if(j==n)cnt++;
    }
    for(i=y1;i<y2;i++)
    {
        for(j=0;j<n;j++)
            if(inn(x2,i,x[j],y[j],r[j]))
                break;
        if(j==n)cnt++;
    }
    for(i=x2;i>x1;i--)
    {
        for(j=0;j<n;j++)
            if(inn(i,y2,x[j],y[j],r[j]))
                break;
        if(j==n)cnt++;
    }
    for(i=y2;i>y1;i--)
    {
        for(j=0;j<n;j++)
            if(inn(x1,i,x[j],y[j],r[j]))
                break;
        if(j==n)cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
