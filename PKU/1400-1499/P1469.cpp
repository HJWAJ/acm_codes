#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

bool mark1[305],mark2[305];
int list[305];
int p,n,edge,num;
vector< vector<int> > v;

bool dfs(int to)
{
    int i,point,s=list[to];
    for(i=0;i<v[s].size();i++)
    {
        point=v[s][i];
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

int Solve()
{
    int i,j,point;
    bool flog=false;
    memset(mark1,true,sizeof(mark1));
    memset(list,-1,sizeof(list));
    num=0;
    for(i=0;i<p;i++)
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
    for(i=0;i<p;i++)
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
    return num;
}

int main()
{
    int i,j,s,d,t,numb;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&p,&n);
        v.clear();
        v.resize(p);
        for(i=0;i<p;i++)
        {
            scanf("%d",&numb);
            for(j=0;j<numb;j++)
            {
                scanf("%d",&d);
                v[i].push_back(d-1);
            }
        }
        if(n<p)
        {
            printf("NO\n");
            continue;
        }
        if(Solve()==p)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
