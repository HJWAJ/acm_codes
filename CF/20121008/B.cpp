#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
using namespace std;
int a[105];
int main()
{
    int n,d,l,i=0;
    scanf("%d%d%d",&n,&d,&l);
    if(d==0)
    {
        while(i<n)a[i++]=1;
        if(n&1)a[1]=2;
        if(n==1)puts("-1");
        else
        {
            for(i=0;i<n-1;i++)printf("%d ",a[i]);
            printf("%d\n",a[i]);
        }
    }
    else if(d>0)
    {
        for(i=0;i<n;i++)a[i]=1;
        if(n&1)d--;
        i=0;
        while(d && i<n)
        {
            while(d && a[i]<l)
            {
                d--;
                a[i]++;
            }
            i+=2;
        }
        if(d)puts("-1");
        else
        {
            for(i=0;i<n-1;i++)printf("%d ",a[i]);
            printf("%d\n",a[i]);
        }
    }
    else
    {
        for(i=0;i<n;i++)a[i]=1;
        if(n&1)d--;
        i=1;
        while(d && i<n)
        {
            while(d && a[i]<l)
            {
                d++;
                a[i]++;
            }
            i+=2;
        }
        if(d)puts("-1");
        else
        {
            for(i=0;i<n-1;i++)printf("%d ",a[i]);
            printf("%d\n",a[i]);
        }
    }
	return 0;
}
