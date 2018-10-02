#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<fstream>
using namespace std;
#define maxn 7000000
#define prime 6999999
struct node
{
    int x,c,next;
};
node data[maxn];
int hash[maxn];
int k[7],p[7];
int total=0,n,m,ans=0;
void init()
{
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",k+i,p+i);
        if(i>(n+1)/2)k[i]=0-k[i];
    }
    memset(hash,0,sizeof(hash));
}
int find(int sum)
{
    int cod,i;
    cod=abs(sum)%prime;
    i=hash[cod];
    while((i>0)&&(data[i].x!=sum))i=data[i].next;
    return i;
}
void add(int sum)
{
    int cod,q;
    q=find(sum);
    if(q>0) data[q].c++;
    else
    {
        total++;
        cod=abs(sum)%prime;
        data[total].next=hash[cod];
        data[total].x=sum;
        hash[cod]=total;
        data[total].c=1;
    }
}
void getans(int  sum)
{
    int q;
    q=find(sum);
    if(q>0)ans+=data[q].c;
}
void dfs(int step,int sum,int lim)
{
    int i;
    if(step>lim)
    {
        if(lim==n)getans(sum);
        else add(sum);
        return;
    }
    for(i=1;i<=m;i++)
        dfs(step+1,sum+k[step]*(int)pow(i*1.0,p[step]),lim);
}
void solve()
{
    dfs(1,0,(n+1)/2);
    dfs((n+3)/2,0,n);
    printf("%d\n",ans);
}
int main()
{
    init();
    solve();
}
