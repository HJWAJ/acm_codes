#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
using namespace std;
int n,mark[105],sum;
struct node
{
	int x,y,z,t;
	int a[8];
	int id;
}p[105];
int d[8][4]={{0,0,0,1},{0,0,0,-1},{0,0,1,0},{0,0,-1,0},{0,1,0,0},{0,-1,0,0},{1,0,0,0},{-1,0,0,0}};
int xmin,xmax,ymin,ymax,zmin,zmax,tmin,tmax;
int find(int k)
{
	int i;
	for(i=0;i<n;i++)
		if(p[i].id==k)
			return i;
	return 0;
}
void dfs(int k)
{
	int i,next_id;
	if(p[k].x<xmin)xmin=p[k].x;
	if(p[k].x>xmax)xmax=p[k].x;
	if(p[k].y<ymin)ymin=p[k].y;
	if(p[k].y>ymax)ymax=p[k].y;
	if(p[k].z<zmin)zmin=p[k].z;
	if(p[k].z>zmax)zmax=p[k].z;
	if(p[k].t<tmin)tmin=p[k].t;
	if(p[k].t>tmax)tmax=p[k].t;
	for(i=0;i<8;i++)
	{
		if(p[k].a[i])
		{
			next_id=find(p[k].a[i]);
			if(mark[next_id]==0)
			{
				mark[next_id]=1;
				sum++;
				p[next_id].x=p[k].x+d[i][0];
				p[next_id].y=p[k].y+d[i][1];
				p[next_id].z=p[k].z+d[i][2];
				p[next_id].t=p[k].t+d[i][3];
				dfs(next_id);
			}
		}
	}
}
int judge()
{
	int i,j,next_id;
	for(i=0;i<n;i++)
	{
		for(j=0;j<8;j++)
			if(p[i].a[j])
			{
				next_id=find(p[i].a[j]);
				if((!(j&1) && p[next_id].a[j+1]!=p[i].id) || (j&1 && p[next_id].a[j-1]!=p[i].id))return 0;
			}
	}
	return 1;
}
int main()
{
	int m,i;
	scanf("%d",&m);
	while(m--)
	{
		memset(mark,0,sizeof(mark));
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%d%d%d%d%d%d%d%d%d",&p[i].id,&p[i].a[0],&p[i].a[1],&p[i].a[2],&p[i].a[3],&p[i].a[4],&p[i].a[5],&p[i].a[6],&p[i].a[7]);
		mark[0]=1;
		sum=1;
		p[0].x=0;
		p[0].y=0;
		p[0].z=0;
		p[0].t=0;
		xmin=0;
		xmax=0;
		ymin=0;
		ymax=0;
		zmin=0;
		zmax=0;
		tmin=0;
		tmax=0;
		dfs(0);
		if(!judge() || sum!=n)printf("Inconsistent\n");
		else printf("%d\n",(xmax-xmin+1)*(ymax-ymin+1)*(zmax-zmin+1)*(tmax-tmin+1));
	}
	return 0;
}
