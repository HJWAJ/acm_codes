#include<iostream>
using namespace std;

struct type
{
    int p,t,d;
};

int q,m;
int link[21][21];
type task[201];
int dis[21][21];
bool con[201][201];
int v[201];
bool b[201];

void floyd()
{
    for(int k=1;k<=q;k++)
        for(int i=1;i<=q;i++)
            for(int j=1;j<=q;j++)
                if(dis[i][k]!=-1&&dis[k][j]!=-1)
                    if(dis[i][j]==-1||dis[i][j]>dis[i][k]+dis[k][j])
                        dis[i][j]=dis[i][k]+dis[k][j];
}

void getgraph()
{
    memset(&con,0,sizeof(con));
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            if(dis[task[i].p][task[j].p]<=task[j].t-(task[i].t+task[i].d))con[i][j]=true;
}

int hungary(int i)
{
    for(int j=1;j<=m;j++)
    {
        if(con[i][j]&&!v[j])
        {
            v[j]=i;
            return 1;
        }
    }
    for(int j=1;j<=m;j++)
    {
        if(con[i][j]&&!b[j])
        {
            b[j]=true;
            if(hungary(v[j]))
            {
                v[j]=i;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    while(cin>>q)
    {
        cin>>m;
        if(q==0)break;
        for(int i=1;i<=q;i++)
            for(int j=1;j<=q;j++)
            {
                cin>>link[i][j];
                dis[i][j]=link[i][j];
            }
        for(int i=1;i<=m;i++)
            cin>>task[i].p>>task[i].t>>task[i].d;
        floyd();
        getgraph();
        memset(v,0,sizeof(v));
        int match=0;
        for(int i=1;i<=m;i++)
        {
            memset(b,0,sizeof(b));
            match+=hungary(i);
        }
        cout<<m-match<<endl;
    }
    return 0;
}
 
