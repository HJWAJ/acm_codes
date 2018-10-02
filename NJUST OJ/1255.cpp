#include<iostream>
#include<cstdio>
#include<cstring>
#include <time.h>
using namespace std;
#define MAXM 1100000
#define MAXN 2000

#define inf 1000000000

int N,M,s,t,P,L;

struct sedge
{
	int u,v,cap;
	int next;
}edge[MAXM];

int head[MAXN],e,e2;

void addedge(int u,int v,int cap)
{
	edge[e].u=u;edge[e].v=v;edge[e].cap=cap;
	edge[e].next=head[u];head[u]=e++;
	edge[e].u=v;edge[e].v=u;edge[e].cap=0;
	edge[e].next=head[v];head[v]=e++;
}

int sap()
{
	int pre[MAXN],dis[MAXN],gap[MAXN],cur[MAXN];
	int aug=inf,u,flow=0;
	bool flag;
	int NN;
	NN=t+1;
	for(int i=0;i<NN;i++)
	{
		cur[i]=head[i];
		dis[i]=gap[i]=0;
	}
	u=pre[s]=s;
	gap[0]=NN;
	while(dis[s]<NN)
	{
		flag=false;
		for(int &j=cur[u];j!=-1;j=edge[j].next)
		{
			int v=edge[j].v;
			if(edge[j].cap>0&&dis[u]==dis[v]+1)
			{
				flag=true;
				if(aug>edge[j].cap)
					aug=edge[j].cap;
				pre[v]=u;
				u=v;
				if(u==t)
				{
					flow+=aug;
					while(u!=s)
					{
						u=pre[u];
						edge[cur[u]].cap-=aug;
						edge[cur[u]^1].cap+=aug;
					}
					aug=inf;
				}
				break;
			}
		}
		if(flag)
			continue;
		int mindis=NN;
		for(int j=head[u];j!=-1;j=edge[j].next)
		{
			int v=edge[j].v;
			if(edge[j].cap>0&&dis[v]<mindis)
			{
				cur[u]=j;
				mindis=dis[v];
			}
		}
		if((--gap[dis[u]])==0)
			break;
		gap[dis[u]=mindis+1]++;
		u=pre[u];
	}
	return flow;
}

int  graph[MAXN][MAXN];

bool fx[MAXN],fy[MAXN];

void init()
{
	memset(head,-1,sizeof(head));
	memset(graph,0,sizeof(graph));
	memset(fx,0,sizeof(fx));
	memset(fy,0,sizeof(fy));
	e=0;
}

void dfsx(int s)
{
	int i;
	fx[s]=true;
	for(i=1;i<=N+1;i++)
	{
		if(!fx[i]&&graph[s][i])
			dfsx(i);
	}
}

void dfsy(int t)
{
	int i;
	fy[t]=true;
	for(i=1;i<=N+1;i++)
	{
		if(!fy[i]&&graph[i][t])
			dfsy(i);           
	}
}

struct node
{
	int u,v;
}subedge[MAXM];

int main()
{
	int i,a,b,c,ans;
	
	//freopen("in.txt","r",stdin);
 //freopen("out.txt","w",stdout);
 //double tt = clock();
	while(scanf("%d%d%d%d",&N,&M,&P,&L)!=EOF)
	{
		init();
		e2=0;
		for(i=0;i<M;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			addedge(a,b,c);
		}
		s=0;
		t=N+1;
		addedge(s,1,inf);
		addedge(N,t,inf);
		ans=sap();
		for(i=0;i<=e;i+=2)
		{
			if(edge[i].cap!=0)
			{
				graph[edge[i].u][edge[i].v]=1;
			}
		}
		dfsx(s);
		dfsy(t);
		for(i=0;i<=e;i+=2)
		{
			if(edge[i].cap==0&&fx[edge[i].u]&&fy[edge[i].v])
			{
				subedge[e2].u=edge[i].u;
				subedge[e2].v=edge[i].v;
				e2++;
			}
		}
		init();
		for(i=0;i<e2;i++)
		{
			addedge(i+1,subedge[i].u+e2,inf);
			addedge(i+1,subedge[i].v+e2,inf);
		}
		s=0;
		t=e2+N+1;
		for(i=1;i<=e2;i++)
		{
			addedge(s,i,L);
		}
		for(i=1;i<=N;i++)
			addedge(i+e2,t,P);
		ans=sap();
		printf("%d\n",e2*L-ans);
	}
	//printf("\n%lf\n",clock()-tt);
	return 0;
}
