/*
ID: hjw00002
PROG: maze1
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
char maze[205][205];
int dx[] = {-1,0,1,0},dirx;
int dy[] = {0,1,0,-1},diry;
struct node
{
	int x,y,cnt;
};
int w,h,W,H;
bool vis[205][205];
int bfs(int x,int y)
{
	if(x == 0 || y == 0 || x == H-1 || y == W-1) return 0;
	queue<node>Q;
	node P;
	P.x = x;
	P.y = y;
    P.cnt = 0;
	Q.push(P);
	memset(vis, 0, sizeof(vis));
	while(!Q.empty())
	{
		node N = Q.front();
		Q.pop();
		if(vis[N.x][N.y] == 1) continue;
		vis[N.x][N.y] = 1;
		for(int dir = 0; dir < 4; dir++)
		{
			int tx = N.x + dx[dir];
			int ty = N.y + dy[dir];
			if((tx >= 0 && ty >= 0 && tx < H && ty < W)	&& (maze[tx][ty] == ' ') && (tx == 0 || ty == 0 || tx == H-1 || ty == W-1))
			{
				return N.cnt+1;
			}
			if(maze[tx][ty] == ' ')
			{
				node tmp;
				tmp.x = tx + dx[dir];
                tmp.y = ty + dy[dir];
                tmp.cnt = N.cnt + 2;
				Q.push(tmp);
			}
		}
	}
	return 0;
}
int main()
{
	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);
	int i,j,res=0,tmp;
	scanf("%d%d",&w,&h);
	getchar();
	w=2*w+1;
	W=w;
	h=2*h+1;
	H=h;
	for(i=0;i<h;i++)
	{
	    string str;
		getline(cin,str);
		strcpy(maze[i],str.c_str());
		for(j=0;j<w;j++)
		{
			if(maze[i][j]=='+' || maze[i][j]=='-' || maze[i][j]=='|')continue;
			else maze[i][j]=' ';
		}
	}
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			if(maze[i][j]==' ' && i%2==1 && j%2==1)
			{
				tmp=bfs(i,j);
				res=max(res,tmp);
			}
		}
	}
	printf("%d\n",(res-1)/2+1);
}
