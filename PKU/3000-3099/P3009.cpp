#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int map[20][20],w,h,moves;

void DFS(int i,int j,int a,int b,int step)
{
	int x=i,y=j;//保存石头的当前位置
	if(step<moves&&i-1>=0&&(map[i-1][j]==0||map[i-1][j]==3))
	{//石头可以向上移动的条件
		while(i-1>=0&&map[i-1][j]==0)i--;//按照游戏规则4向上移动
		if(i>0&&map[i-1][j]==3){moves=step;}//到达目的地
		if(i>0&&map[i-1][j]==1)//碰到积木
		{
			map[i-1][j]=0;//积木消失
			DFS(i,j,i-1,j,step+1);//继续移动
		}
	}
	i=x;
	j=y;
	if(step<moves&&j-1>=0&&(map[i][j-1]==0||map[i][j-1]==3))
	{//石头可以向左移动的条件
		while(j-1>=0&&map[i][j-1]==0)j--;//按照游戏规则4向左移动
		if(j>0&&map[i][j-1]==3){moves=step;}//到达目的地
		if(j>0&&map[i][j-1]==1)//碰到积木
		{
			map[i][j-1]=0;//积木消失
			DFS(i,j,i,j-1,step+1);//继续移动
		}
	}
	i=x;
	j=y;
	if(step<moves&&i+1<h&&(map[i+1][j]==0||map[i+1][j]==3))
	{//石头可以向下移动的条件
		while(i+1<h&&map[i+1][j]==0)i++;//按照游戏规则4向下移动
		if(i<h-1&&map[i+1][j]==3){moves=step;}//到达目的地
		if(i<h-1&&map[i+1][j]==1)//碰到积木
		{
			map[i+1][j]=0;//积木消失
			DFS(i,j,i+1,j,step+1);//继续移动
		}
	}
	i=x;
	j=y;
	if(step<moves&&j+1<w&&(map[i][j+1]==0||map[i][j+1]==3))
	{//石头可以向右移动的条件
		while(j+1<w&&map[i][j+1]==0)j++;//按照游戏规则4向右移动
		if(j+1<w&&map[i][j+1]==3){moves=step;}//到达目的地
		if(j+1<w&&map[i][j+1]==1)//碰到积木
		{
			map[i][j+1]=0;//积木消失
			DFS(i,j,i,j+1,step+1);//继续移动
		}
	}
	map[a][b]=1;//还原积木
}

int main()
{
	int i,j,a,b;
	while(1)
	{
		scanf("%d%d",&w,&h);
		if(w==0&&h==0)break;
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				scanf("%d",&map[i][j]);
				if(map[i][j]==2)
				{
					map[i][j]=0;//把起点变成空白点
					a=i;//a，b表示起点坐标
					b=j;
				}
			}
		}
		moves=11;//最多可移动10次
		DFS(a,b,a,b,1);
		printf("%d\n",moves<11?moves:-1);
	}
	
	return 0;
}
