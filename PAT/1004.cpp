#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v[105];
int level[105],cnt[105],highlevel=0;
void dfs(int id,int nowlevel)
{
    level[id]=nowlevel;
    if(nowlevel>highlevel)highlevel=nowlevel;
    for(int i=0;i<v[id].size();i++)
        dfs(v[id][i],nowlevel+1);
}
int main()
{
    int n,m,id,num,child;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d%d",&id,&num);
        while(num--)
        {
            scanf("%d",&child);
            v[id].push_back(child);
        }
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        if(v[i].size()==0)
            cnt[level[i]]++;
    for(int i=0;i<highlevel;i++)printf("%d ",cnt[i]);
    printf("%d\n",cnt[highlevel]);
    return 0;
}
