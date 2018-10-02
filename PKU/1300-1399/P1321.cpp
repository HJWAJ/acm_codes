#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<cmath>
#include<string>
using namespace std;
int u[1024],g[1024],f[1024];
char s[15][15];
int main()
{
    int n,m,i,j,k,e,ans;
    while(scanf("%d%d",&n,&m) && (n!=-1 || m!=-1))
    {
        e=(1<<n);
        for(i=1;i<=n;i++)scanf("%s",s[i]+1);
        memset(u,0,sizeof(u));
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        for(i=0;i<=e;i++)
        {
            j=0;
            k=i;
            while(k>0)
            {
                if(k&1)j++;
                k>>=1;
            }
            if(j==m)u[i]=1;
        }
        g[0]=1;
        ans=0;
        for(i=1;i<=n;i++)
        {
            memset(f,0,sizeof(f));
            for(j=1;j<=n;j++)
            {
                if(s[i][j]=='.')continue;
                for(k=0;k<=e;k++)
                {
                    if((k&(1<<(j-1)))>0)continue;
                    f[k+(1<<(j-1))]+=g[k];
                }
            }
            for(j=0;j<=e;j++)g[j]+=f[j];
        }
        for(i=0;i<=e;i++)
            if(u[i])
                ans+=g[i];
        printf("%d\n",ans);
    }
    return 0;
}
