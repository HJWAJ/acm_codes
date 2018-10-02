#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<fstream>
using namespace std;
bool mark1[100],mark2[100];
int list[100];
int n,m,edge,num;
vector< vector<int> > v;

bool dfs(int to)
{
    int i,point,s = list[to];
    for(i=0;i<v[s].size();i++)
    {
        point = v[s][i];
        if(!mark2[point])continue;
        mark2[point]=false;
        if(list[point]==-1 || dfs(point))
        {
            list[point]=s;
            return true;
        }
    }
    return false;
}

void Solve()
{
    int i,j,point;
    bool flog=false;
    memset(mark1,true,sizeof(mark1));
    memset(list,-1,sizeof(list));
    num=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<v[i].size();j++)
        if(list[v[i][j]]==-1)
        {
            mark1[i]=false;
            list[v[i][j]]=i;
            num++;
            if(i==0)flog=true;
            break;
        }
    }
    for(i=0;i<n;i++)
    {
        if(mark1[i])
        {
            if(!v[i].empty())
            {
                memset(mark2,true,sizeof(mark2));
                for(j=0;j<v[i].size();j++)
                {
                    point=v[i][j];
                    if(!mark2[point])continue;
                    mark2[point]=false;
                    if(list[point]==-1 || dfs(point))
                    {
                        list[point]=i;
                        num++;
                        break;
                    }
                }
            }
            mark1[i]=false;
        }
    }
    cout<<num<<endl;
}

int main()
{
    int i,j,s,d;
    while(scanf("%d",&n) && n)
    {
        scanf("%d%d",&m,&edge);
        v.clear();
        v.resize(n+m);
        for(i=0;i<edge;i++)
        {
            scanf("%d%d%d",&j,&s,&d);
            if(s!=0 && d!=0)v[s].push_back(d);
        }
        Solve();
    }
    return 0;
}
