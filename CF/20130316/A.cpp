#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
int m,n,a[105][105];
int INF=(1<<30);
int main()
{
    int i,j,ans,tmp;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ans=INF;
        for(i=0;i<=n;i++)a[i][0]=a[0][i]=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
                a[i][j]+=a[i][j-1];
            }
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                a[i][j]+=a[i-1][j];
        for(i=1;i<=n-m+1;i++)
            for(j=1;j<=n-m+1;j++)
            {
                tmp=a[i+m-1][j+m-1]+a[i-1][j-1]-a[i+m-1][j-1]-a[i-1][j+m-1];
                if(tmp<ans)ans=tmp;
            }
        printf("%d\n",ans);
    }
    return 0;
}
