#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
struct Node
{
    int x;
    int y;
    int step;
    Node(int x0=0,int y0=0,int s0=0)
    {
        x=x0;
        y=y0;
        step=s0;
    }
};

const int maxN=1005;
int Size,shopNum,customerNum,obstacleNum;
int grid[maxN][maxN];
int dir[4][2]= {{-1,0},{0,1},{1,0},{0,-1}};
queue<Node> q;

void bfs()
{
    Node u;
    int i,vx,vy,vs;
    long long cost=0;

    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0; i<4; i++)
        {
            vx=u.x+dir[i][0];
            vy=u.y+dir[i][1];
            if( vx>0 && vx<=Size && vy>0 && vy<=Size && !(grid[vx][vy]&1) )
            {
                vs=u.step+1;
                grid[vx][vy] |= 1;
                if(grid[vx][vy]&2)cost+=vs*(grid[vx][vy]>>2);
                q.push(Node(vx,vy,vs));
            }
        }
    }
    cout<<cost<<endl;
}

int main()
{
    int i,a,b,c;
    while(scanf("%d%d%d%d",&Size,&shopNum,&customerNum,&obstacleNum)!=EOF)
    {
        while(!q.empty())q.pop();
        memset(grid,0,sizeof(grid));
        for(i=0; i<shopNum; i++)
        {
            scanf("%d%d", &a, &b);
            grid[a][b] |= 1;
            q.push(Node(a,b));
        }
        for(i=0; i<customerNum; i++)
        {
            scanf("%d%d%d", &a,&b,&c);
            grid[a][b] = (grid[a][b]|2) + (c<<2);
        }
        for(i=0; i<obstacleNum; i++)
        {
            scanf("%d%d", &a, &b);
            grid[a][b] |= 1;
        }
        bfs();
    }
    return 0;
}