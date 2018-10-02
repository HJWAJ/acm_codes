/*
ID: hjw00002
PROG: milk2
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
using namespace std;

bool val[1000005];

int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    int n,l,r,i,j,max=0,min=9999999,max1=0,max0=0,cnt1=0,cnt0=0;
    scanf("%d",&n);
    memset(val,0,sizeof(val));
    while(n--)
    {
        scanf("%d%d",&l,&r);
        if(max<r)max=r;
        if(min>l)min=l;
        for(i=l+1;i<=r;i++)val[i]=1;          
    }
    
    for(i=min+1;i<=max;i++)
    {
        if(val[i]==0)
        {
            cnt0++;
            if(max0<cnt0)max0=cnt0;
            cnt1=0;
        }
        if(val[i]==1)
        {
            cnt1++;
            if(max1<cnt1)max1=cnt1;
            cnt0=0;
        }
    }
    printf("%d %d\n",max1,max0);
    
    //system("pause");
    return 0;
}
