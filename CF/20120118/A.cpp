#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n,i,a[105],max=-1,min=99999,maxp,minp,aa[105],step1=0,step2=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",a+i);
    memcpy(aa,a,sizeof(a));
    for(i=0;i<n;i++)
        if(a[i]>max)
        {
            max=a[i];
            maxp=i;
        }
    for(i=maxp;i>0;i--)
    {
        swap(a[i],a[i-1]);
        step1++;
    }
    for(i=0;i<n;i++)
        if(a[i]<=min)
        {
            min=a[i];
            minp=i;
        }
    for(i=minp;i<n-1;i++)
    {
        swap(a[i],a[i+1]);
        step1++;
    }
    min=99999;max=-1;
    for(i=0;i<n;i++)
        if(aa[i]<=min)
        {
            min=aa[i];
            minp=i;
        }
    for(i=minp;i<n-1;i++)
    {
        swap(aa[i],aa[i+1]);
        step2++;
    }
    for(i=0;i<n;i++)
        if(aa[i]>max)
        {
            max=aa[i];
            maxp=i;
        }
    for(i=maxp;i>0;i--)
    {
        swap(aa[i],aa[i-1]);
        step2++;
    }
    if(step1>step2)step1=step2;
    printf("%d\n",step1);
    return 0;
}
