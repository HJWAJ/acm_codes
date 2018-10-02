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

int map[155][15];
int tri[12]= {0,1,3,9,27,81,243,729,2187,6561,19683,59049};
int dp[2][59049];// 用滚动数组记录每一行的状态
int pre[15],now[15];//上一行与本行的三进制状态
int n,m;
int max(int a,int b)
{
    return (a>=b)?a:b;
}
int getten(int a[])// 把三进制状态转换为十进制数
{
    int sum=0;
    for(int i=1; i<=m; ++i)
        sum+=tri[i]*a[i];
    return sum;
}
void gettri(int k,int a[])// 把十进制数转换成三进制数组
{
    for(int i=1; i<=m; ++i)
    {
        a[i]=k%3;
        k=k/3;
    }
    return;
}
void dfs(int i,int j,int last,int key)
//四个参数：i当前行，j当前列，当前状态值，当前状态
{
    int k;
    dp[i%2][key]=max(dp[i%2][key],last);//不做改动，更新父状态
    if(j>=m)
        return;
    if(!pre[j] && !pre[j+1] && !now[j] && !now[j+1])//竖着切割
    {
        now[j]=now[j+1]=2;
        k=getten(now);
        dfs(i,j+2,last+1,k);
        now[j]=now[j+1]=0;
    }
    if(j<m-1 && !now[j] && !now[j+1] && !now[j+2])//横着切割
    {
        now[j]=now[j+1]=now[j+2]=2;
        k=getten(now);
        dfs(i,j+3,last+1,k);
        now[j]=now[j+1]=now[j+2]=0;
    }
    dfs(i,j+1,last,key);//不做改动，深搜下一列
    return;
}
int main ()
{
    int nn,k,a,b,tmp,ans;
    scanf("%d",&nn);
    while(nn--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0; i<tri[m+1]; ++i)
            dp[1][i]=-1;// 先初始化第1行的全部状态都是不可能形成的
        for(int i=1; i<=m; ++i)
            for(int j=1; j<=n; ++j)
                map[j][i]=0;
        for(int i=1; i<=k; ++i)
        {
            scanf("%d%d",&a,&b);
            map[a][b]=1;
        }
        for(int i=1; i<=m; ++i)
            pre[i]=map[1][i]+1;//计算第1行的状态第0行的方块全部视为不可用
        tmp=getten(pre);
        dp[1][tmp]=0;//设置第一行的原本状态是可以形成的，状态值为0
        for(int i=2; i<=n; ++i)// 枚举子状态
        {
            for(int j=0; j<tri[m+1]; ++j)// 先设置父状态值为-1，等待更新
                dp[i%2][j]=-1;
            for(int j=0; j<tri[m+1]; ++j)
            {
                if(dp[(i+1)%2][j]==-1)// 跳过不可能的子状态
                    continue;
                gettri(j,pre);
                for(int t=1; t<=m; ++t)
                {
                    if(map[i][t])
                        now[t]=2;
                    else
                        now[t]=max(pre[t]-1,0);
                }//根据上一行的状态得到本行的状态
                tmp=getten(now);
                dfs(i,1,dp[(i+1)%2][j],tmp);
//深搜这一层所有可能的状态
            }
        }
        ans=0;
        for(int i=0; i<tri[m+1]; ++i)
            ans=max(ans,dp[n%2][i]);// 得到答案
        printf("%d\n",ans);
    }
    return 0;
}
