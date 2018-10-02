#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

bool mark1[505],mark2[505];
int list[505];
int m,n,edge,num,numb;
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
    for(i=0;i<numb;i++)
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
    for(i=0;i<numb;i++)
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

int getnum(char tmp[])
{
    int len=strlen(tmp),res=0,i;
    for(i=1;i<len-1;i++)
    {
        res*=10;
        res+=(tmp[i]-'0');
    }
    return res;
}

int main()
{
    int i,j,s,d,g[505][505],flag[505],mm,nn;
    char tmp[105];
    while(scanf("%d",&numb)!=EOF)
    {
        memset(g,0,sizeof(g));
        memset(flag,0,sizeof(flag));
        v.clear();
        v.resize(numb);
        for(i=0;i<numb;i++)
        {
            scanf("%d",&mm);
            scanf("%s",tmp);
            scanf("%s",tmp);
            nn=getnum(tmp);
            for(j=0;j<nn;j++)
            {
                scanf("%d",&d);
                //g[mm][d]=1;
                v[mm].push_back(d);
            }
        }
        /*/
        for(i=0;i<numb;i++)
            for(j=0;j<numb;j++)
            {
                if(g[i][j])flag[j]=flag[i]+1;
            }
        n=m=0;
        for(i=0;i<numb;i++)
        {
            if(flag[i]&1)n++;
            else m++;
        }
        v.clear();
        v.resize(numb);
        for(i=0;i<numb;i++)
            if(flag[i]&1)
                for(j=0;j<numb;j++)
                    if(g[i][j])v[i].push_back(j);
        //*/
        printf("%d\n",numb-Solve());
    }
    return 0;
}
