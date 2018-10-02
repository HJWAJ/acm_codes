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
#include<windows.h>
using namespace std;
const __int64 mod=1000000007;
__int64 resnow=0,res=0;
int t[100005];
__int64 w[100005];
__int64 find(int i,int v,int x,__int64 weight)
{
    __int64 ww;
    if(!t[v])
    {
        t[v]=i;
        w[v]=(weight+x)%mod;
        return resnow=w[v];
    }
    else
    {
        ww=find(i,t[v],x,weight+w[v]);
        t[v]=i;
        return w[v]=(ww+w[v])%mod;
    }
}
int main()
{
    int n,i,j,k,v,x;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&k);
        for(j=0;j<k;j++)
        {
            scanf("%d%d",&v,&x);
            find(i,v,x,0);
            res=(res+resnow)%mod;
        }
        if(res<0)res+=mod;
    }
    printf("%I64d\n",res);
    return 0;
}
