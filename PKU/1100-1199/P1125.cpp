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
int main()
{
    int i,j,k,n,max,x,y,a[10000],b[200][200],max1,tt;
    while(1)
    {
        scanf("%d",&n);
        if (n==0) break;
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                b[i][j]=100000000;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            for(j=1; j<=a[i]; j++)
            {
                scanf("%d%d",&x,&y);
                b[i][x]=y;
            }
        }
        for(k=1; k<=n; k++)
            for(i=1; i<=n; i++)
                for(j=1; j<=n; j++)
                    if (b[i][k]+b[k][j]<b[i][j]) b[i][j]=b[i][k]+b[k][j];
        tt=100000000;
        for(i=1; i<=n; i++)
        {
            max=0;
            b[i][i]=0;
            for(j=1; j<=n; j++)
                if (b[i][j]>max) max=b[i][j];
            if (tt>max)
            {
                tt=max;
                max1=i;
            }
        }
        if (tt==100000000) printf("disjoint\n");
        else
            printf("%d %d\n",max1,tt);
    }
    return 0;
}
