#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<queue>
#include<string>
#include<vector>
using namespace std;

const int INF = 1000000000;
const int MAXN = 10001;
const int MAXM = 100000;

int n, m,i,s,ll,cnt=0;
int first[MAXN], d[MAXN];
int u[MAXM], v[MAXM], w[MAXM], next[MAXM];

typedef pair<int,int> pii;

int main()
{
    scanf("%d%d%d", &n, &m, &s);
    s--;
    for(i = 0; i < n; i++) first[i] = -1;
    for(int e = 0; e < m; e++)
    {
        scanf("%d%d%d", &u[e], &v[e], &w[e]);
        u[e]--;
        v[e]--;
        if(u[e]==s)u[e]=0;
        if(v[e]==s)v[e]=0;
        if(u[e]==0)u[e]=s;
        if(v[e]==0)v[e]=s;
        next[e] = first[u[e]];
        first[u[e]] = e;
    }
    scanf("%d",&ll);
    priority_queue<pii, vector<pii>, greater<pii> > q;
    bool done[MAXN];
    for(i = 0; i < n; i++) d[i] = (i==0 ? 0 : INF);
    memset(done, 0, sizeof(done));
    q.push(make_pair(d[0], 0));
    while(!q.empty())
    {
        pii u = q.top();
        q.pop();
        int x = u.second;
        if(done[x]) continue;
        done[x] = true;
        for(int e = first[x]; e != -1; e = next[e]) if(d[v[e]] > d[x]+w[e])
            {
                d[v[e]] = d[x] + w[e];
                q.push(make_pair(d[v[e]], v[e]));
            }
    }

    for(int i = 0; i < n; i++)
    {
        if(d[i]>=ll)cnt++;
        //cout<<d[i]<<endl;
    }
    printf("%d\n",cnt);
    return 0;

}
