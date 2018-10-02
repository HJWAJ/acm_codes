#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<vector>
using namespace std;
vector<int> vec[100500];
bool bo[100500];
struct nod
{
    int s,t;
}node[100500];
int cnt=0;
void dfs(int n)
{
    int i,j;
    bo[n]=1;
    for(i=0;i<vec[n].size();i++)
    {
        if(!bo[vec[n][i]])
        {
            node[cnt].s=n;
            node[cnt++].t=vec[n][i];
            for(j=0;j<vec[vec[n][i]].size();j++)
                if(vec[vec[n][i]][j]==n)break;
            vec[vec[n][i]].erase(vec[vec[n][i]].begin()+j);
            dfs(vec[n][i]);
            vec[n].erase(vec[n].begin()+i);
            break;
        }
    }
}
int main()
{
    int n,m,i,j,k,u,v;
    scanf("%d%d",&n,&m);
    memset(bo,0,sizeof(bo));
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        vec[u-1].push_back(v-1);
        vec[v-1].push_back(u-1);
    }
    /*
    for(i=0;i<n;i++)
    {
        cout<<i<<": ";
        for(j=0;j<vec[i].size();j++)cout<<vec[i][j]<<' ';
        cout<<endl;
    }
    */
    dfs(0);
    for(i=0;i<n;i++)
        if(!bo[i])
        {
            puts("0");
            return 0;
        }
    //cout<<cnt<<endl;
    for(i=0;i<cnt;i++)
        printf("%d %d\n",node[i].s+1,node[i].t+1);
    for(i=0;i<n;i++)
        for(j=0;j<vec[i].size();j++)
        {
            for(k=0;k<vec[vec[i][j]].size();k++)
                if(vec[vec[i][j]][k]==i)break;
            vec[vec[i][j]].erase(vec[vec[i][j]].begin()+k);
            printf("%d %d\n",i+1,vec[i][j]+1);
        }
    return 0;
}
