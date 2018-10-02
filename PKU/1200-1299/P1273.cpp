#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
#include<ctime>
//#include<windows.h>
using namespace std;
#define Node 20100  //����
#define Edge 604000  //����
#define  INF 999999999999999LL  //�����,����flowtype�Ĳ�ͬ����ֵҪ�޸Ĵ�С
#define  flowtype __int64

struct Graph
{
    struct G_Edge
    {
        int to,next;
        flowtype val;
    }edge[Edge];
    int head[Node];//��ͷ
    int level[Node];//���ͼ
    int que[Node];//����
    int vis[Node];//���ͼ��¼�Ƿ���ʹ�
    int p,N,num;//NΪ����
    void init()
    {
        p= num =0;
        for(int i=0;i<=N+1;i++)head[i]=-1;
    }
    void insert(int a,int b,flowtype c,flowtype c_rev)
        //ǰ���ǹ�ͼ��c�������������c_rev�Ƿ����.
        //�������ı߶��ǳɶԹ���,������:��������һ�Աߣ�֪����һ������һ��ֻҪ���1.
    {
        edge[p].next=head[a];
        edge[p].to=b;
        edge[p].val=c;
        head[a]=p++;
        edge[p].next=head[b];
        edge[p].to=a;
        edge[p].val=c_rev;
        head[b]=p++;
    }
    bool bfs_level(int src,int des)//������ͼ
    {
        memset(level,-1,sizeof(level));
        int q,p,index,i;
        q=p=0;
        que[q++]=src;
        level[src]=0;
        while(p!=q)
        {
            index=que[p++];
            for(i=head[index];i!=-1;i=edge[i].next)
            {
                int v=edge[i].to;
                if(edge[i].val>0&&level[v]==-1)
                {
                    level[v]=level[index]+1;
                    que[q++]=v;
                }
            }
        }
        return level[des]!=-1;
    }
    flowtype dinic(int cur,int des,flowtype lim)//��·����dinic
    {
        if(cur==des)return lim;
        int index,i;
        flowtype mul_flow=0,one_flow;//��·������
        for(i=head[cur];i!=-1&&lim-mul_flow>0;i=edge[i].next)
        {
            index=edge[i].to;
            if(edge[i].val>0&&level[cur]==level[index]-1)
            {
                one_flow=dinic(index,des,min(edge[i].val,lim-mul_flow));
                if(!one_flow)level[index]=-1;
                else
                {
                    mul_flow+=one_flow;
                    edge[i].val-=one_flow;
                    edge[i^1].val+=one_flow;
                }
            }
        }
        return mul_flow;
    }
    flowtype max_flow(int src,int des)
    {
        flowtype ans=0;
        while(bfs_level(src,des))
        {
            num++;
            ans+=dinic(src,des,INF);
        }
        return ans;
    }
}g;
int n, m;
int main()
{
    int i, icase, tt = 0;
    while(scanf("%d%d", &m, &n)!=EOF)
    {
        g.N = n + 2;//here
        g.init();//here
        int a, b;
        __int64 c;
        for (i = 0; i < m; i++)
        {
            scanf("%d%d%I64d", &a, &b, &c);
            g.insert(a-1,b-1,c,0);
        }
        printf("%I64d\n",g.max_flow(0, n - 1));
    }
    return 0;
}
