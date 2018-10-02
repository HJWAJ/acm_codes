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
using namespace std;
int t[105],n,a,b;
int main()
{
    int i;
    scanf("%d%d%d",&n,&a,&b);
    if(n==1)
    {
        puts("1");
        return 0;
    }
    if(a==n-1)
    {
        puts("-1");
        return 0;
    }
    if(b==0)
    {
        printf("1");
        for(i=1;i<n-a;i++)printf(" 1");
        for(i=0;i<a;i++)printf(" %d",i+2);
        puts("");
        return 0;
    }
    t[0]=1;
    for(i=0;i<b;i++)t[i+1]=t[i]*2;
    for(i=0;i<a;i++)t[i+b+1]=t[i+b]+1;
    for(i=a+b+1;i<n;i++)t[i]=1;
    for(i=0;i<n-1;i++)printf("%d ",t[i]);
    printf("%d\n",t[n-1]);
    return 0;
}
