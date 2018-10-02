#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int a[1005],cnt;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,i,j,num,step,k;
    scanf("%d",&n);
    for(i=1;i<=10;i++)
        if(n<=(1<<i))
            break;
    printf("%d\n",i);
    step=1;
    num=i;
    for(i=0;i<num;i++)
    {
        cnt=0;
        for(j=0;j<n;j+=2*step)
        {
            for(k=j;k<j+step && k<n;k++)a[cnt++]=k;
        }
        printf("%d ",cnt);
        for(j=0;j<cnt-1;j++)printf("%d ",a[j]+1);
        printf("%d\n",a[j]+1);
        step*=2;
    }
    return 0;
}
