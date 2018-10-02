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
#include<list>
#include<deque>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<fstream>
using namespace std;
int g[1005][1005];
bool bo[1005];
struct answ
{
    int s,e,d;
}ans[1005];
int flag=0;
int cmp(const void *p,const void *q)
{
    answ *a=(answ *)p;
    answ *b=(answ *)q;
    return a->s - b->s;
}
int main()
{
    int n,p,s,e,d,i,j;
    memset(g,0,sizeof(g));
    memset(bo,0,sizeof(bo));
    scanf("%d%d",&n,&p);
    for(i=0;i<n;i++)ans[i].d=99999999;
    for(i=0;i<p;i++)
    {
        scanf("%d%d%d",&s,&e,&d);
        g[s-1][e-1]=d;
    }
    for(i=0;i<n;i++)
    {
        int ii=i;
        for(j=0;j<n;j++)
            if(g[j][i])break;
        if(j!=n)continue;
        ans[flag].s=i;
        label:;
        for(j=0;j<n;j++)
        {
            if(g[i][j])
            {
                ans[flag].e=j;
                if(ans[flag].d>g[i][j])ans[flag].d=g[i][j];
                i=j;
                goto label;
            }
        }
        flag++;
        i=ii;
    }
    qsort(ans,flag,12,cmp);
    printf("%d\n",flag);
    for(i=0;i<flag;i++)
        printf("%d %d %d\n",ans[i].s+1,ans[i].e+1,ans[i].d);
    return 0;
}
