#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXNODE 300
#define MAXEDGE MAXNODE*MAXNODE
#define MIN(a,b) ((a)<(b)?(a):(b))
#define OPPOSITE(x) (((x)&1)?((x)+1):((x)-1))
#define INFINIT ~0U>>1

using namespace std;

int n,m,E;
int N,S,T;
int head[MAXNODE+1],to[MAXEDGE+1],nex[MAXEDGE+1],c[MAXEDGE+1],cost[MAXEDGE+1],d[MAXNODE+1],cur[MAXNODE+1];
bool visit[MAXNODE+1];
int Count = 0;

int aug(int u,int f){
   if (u == T) return f;
    visit[u] = true;
    for (int now = cur[u]; now; now = nex[now])
        if (c[now]&&!visit[to[now]]&&d[u] == d[to[now]]+cost[now])
            if (int tmp = aug(to[now],MIN(f,c[now])))
                return c[now] -= tmp,c[OPPOSITE(now)] += tmp,cur[u] = now,tmp;
    return 0;
}

bool modlabel(){
   int tmp = INFINIT;
    for (int i = 1; i<=N; i++)
        if (visit[i])
            for (int now = head[i]; now; now = nex[now])
                if (c[now]&&!visit[to[now]])
                    tmp = MIN(tmp,d[to[now]]+cost[now]-d[i]);
    if (tmp == INFINIT)
        return true;
    for (int i = 1; i<=N; i++)
        if (visit[i])
            visit[i] = false,d[i] += tmp;
    if(d[S]>E)
    return true;
    return false;
}

int CostFlow(){
    int costflow = 0,tmp;
    while (true){
        for (int i = 1; i<=N; i++) cur[i] = head[i];
        while (tmp = aug(S,~0U>>1)){
            costflow += tmp;
            memset(visit,0,sizeof(visit));
        }
        if (modlabel())
            break;
    }
    return costflow;
}
void AddEdge(int a,int b,int flow, int v){
    Count++; nex[Count] = head[a]; head[a] = Count; to[Count] = b; c[Count] = flow; cost[Count] = v;
    Count++; nex[Count] = head[b]; head[b] = Count; to[Count] = a; c[Count] = 0; cost[Count] = -v;
}

int main()
{
    int ans,tcas,a,b,c,i;
    scanf("%d",&tcas);
    while(tcas--)
    {
        Count=0;
        scanf("%d%d%d",&n,&m,&E);
        S=1;
        T=N=n;
        for(i=1;i<=n;i++)
          head[i]=0;
        for(i=0;i<m;i++)
        {
             scanf("%d%d%d",&a,&b,&c);
             AddEdge(a,b,c,1);
        }
        ans=CostFlow();
        printf("%d\n",ans);
    }
    return 0;
}