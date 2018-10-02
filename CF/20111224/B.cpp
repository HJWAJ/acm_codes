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
__int64 a[505],b[505],c[505],h[505],w[505],p[505],cnt,numh,numw;
int main()
{
    __int64 n,m,min,i,j,minp=0;
    scanf("%I64d",&n);
    for(i=0;i<n;i++)scanf("%I64d%I64d%I64d",a+i,b+i,c+i);
    scanf("%I64d",&m);
    for(i=0;i<m;i++)scanf("%I64d%I64d%I64d",h+i,w+i,p+i);
    for(i=0;i<n;i++)
    {
        min=999999999;
        for(j=0;j<m;j++)
        {
            if(h[j]>=c[i])
            {
                numh=h[j]/c[i];
                if((a[i]+b[i])*2%w[j]==0)numw=(a[i]+b[i])*2/w[j];
                else numw=(a[i]+b[i])*2/w[j]+1;
                if(numw%numh==0)cnt=numw/numh;
                else cnt=numw/numh+1;
                if(min>cnt*p[j])min=cnt*p[j];
            }
            else continue;
        }
        minp+=min;
    }
    printf("%I64d\n",minp);
    return 0;
}
