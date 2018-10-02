#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double pi=acos(-1.0);
double a[100005];
int main()
{
    int n,i,x,y;
    double m=0.0,tmp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        a[i]=atan2((double)x,(double)y);
        if(a[i]<0)a[i]+=pi*2;
        a[i]=a[i]/pi*180;
    }
    sort(a,a+n);
    for(i=0;i<n-1;i++)
    {
        tmp=a[i+1]-a[i];
        if(tmp>m)m=tmp;
    }
    tmp=a[0]-a[n-1]+360;
    if(tmp>m)m=tmp;
    printf("%.16lf\n",360-m);
    return 0;
}
