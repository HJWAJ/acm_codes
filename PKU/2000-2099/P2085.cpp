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
using namespace std;
int a[50005],b[50005];
int main()
{
    __int64 n,m;
    int i,aa,bb;
    while(scanf("%I64d%I64d",&n,&m) && n>0)
    {
        aa=bb=0;
        for(i=1;i<=n;i++)
        {
            if(n-i<=m&&m>0&&(n-i-1)*(n-i)/2<m)
            {
                m-=(n-i);
                b[bb++]=i;
            }
            else a[aa++]=i;
        }
        for(i=0;i<aa;i++)printf("%d ",a[i]);
        for(i=bb-1;i>0;i--)printf("%d ",b[i]);
        printf("%d\n",b[0]);
    }
    return 0;
}
