#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <queue>
#include <iostream>
using namespace std;
int n,m;		//n是传入的点数，模板中有使用这个参数，很重要
#define Edge  40010000	//图的边数
#define Node 4001000	//点数
#define  INF ((1<<30)-1)
struct E
{
    int to,val,next;
}edge[Edge];
struct node
{
    int v,dis;
    bool operator < (const node & a)const	//优先队列出队顺序
    {
        return dis>a.dis;
    }
};
priority_queue<node>myque;

int head[Node];
int vis[Node];
int dist[Node];
int p=0;
void insert(int x,int y,int c)
{
    edge[p].next=head[x];
    edge[p].val=c;
    edge[p].to=y;
    head[x]=p++;
}

void dij(int src)
{
    node index,temp;
    memset(vis,0,sizeof(vis));
    index.v=src;
    for(int i=0;i<=n+1;i++)
        dist[i]=INF;
    index.dis=0;
    vis[src]=1;
    dist[src]=0;
    myque.push(index);
    while(!myque.empty())
    {
        index=myque.top();
        myque.pop();
        vis[index.v]=1;

        for(int i=head[index.v];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(!vis[v]&&dist[v]>dist[index.v]+edge[i].val)
            {
                temp.v=v;
                temp.dis=dist[v]=dist[index.v]+edge[i].val;
                myque.push(temp);
            }
        }
    }

}


int main()
{
   int N,t,p1,p2;
   while(scanf("%d",&N)!=EOF)
   {
	   n = (N-1)*(N-1)+2;
	   for(int i=0;i<=n;i++)
		   head[i]=-1;
	   p=0;
	   for(int i=1;i<=2*N-1;i++)
	   {
		   for(int j=1;j<=N-i%2;j++)
		   {
			   scanf("%d",&t);
			   if(i%2)
			   {
				   p1 = (i/2-1)*(N-1)+j;
				   if(i==1)p1 = n;
				   p2 = (i/2)*(N-1)+j;
				   if(i==2*N-1)p2 = 0;
				   insert(p2,p1,t);
				   insert(p1,p2,t);
			   }
			   else
			   {
				   p1 = (i/2-1)*(N-1)+j-1;
				   if(j==1)p1 = 0;
				   p2 = (i/2-1)*(N-1)+j;
				   if(j==N)p2 = n;
				   insert(p1,p2,t);			
				   insert(p2,p1,t);
			   }			 
		   }
	   }
	   dij(0);
	   printf("%d\n",dist[n]);
   }
   return 0;
}