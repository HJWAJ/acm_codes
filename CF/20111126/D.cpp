#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std;
bool vis[3005];
bool ring[3005];
vector<int> v[3005];
bool flag=0;
int cnt[3005];
int tmp;
void dfs(int n)
{
    vis[n]=1;
    int num=v[n].size(),i;
    for(i=0;i<num;i++)
    {
        if(vis[v[n][i]] && v[n][i]!=tmp)
        {
            //system("pause");
            //cout<<"1 ";
            //cout<<v[n][i]<<' '<<n<<' '<<i<<endl;
            flag=1;
            ring[v[n][i]]=1;
            ring[n]=1;
            return ;
        }
        else if(v[n][i]==tmp)
        {
            //cout<<3<<endl;
            continue;
        }
        else
        {
            //system("pause");
            tmp=n;
            //cout<<"2 ";
            //cout<<tmp<<' '<<n<<' '<<i<<endl;
            dfs(v[n][i]);
            if(flag)
            {
                ring[n]=1;
                return ;
            }
        }
    }
}
int dfss(int n)
{
    if(ring[n])return 0;
    int num=v[n].size(),i;
    vis[n]=1;
    for(i=0;i<num;i++)
    {
        if(!vis[v[n][i]])return dfss(v[n][i])+1;
    }
}
int main()
{
    int n,i,a,b,j;
    tmp=-1;
    scanf("%d",&n);
    for(i=0;i<n;i++)v[i].clear();
    memset(vis,0,sizeof(vis));
    memset(ring,0,sizeof(ring));
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    dfs(0);
    memset(cnt,0,sizeof(cnt));
    for(i=0;i<n;i++)
    {
        if(ring[i])cnt[i]=0;
        else
        {
            memset(vis,0,sizeof(vis));
            cnt[i]=dfss(i);
        }
    }
    printf("%d",cnt[0]);
    for(i=1;i<n;i++)printf(" %d",cnt[i]);
    puts("");
    return 0;
}
