#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
int g[1005][1005];
int n,m;
int check(int x,int y)
{
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            if(!g[x-1+i][y-1+j])
                return 0;
    return 1;
}
int main()
{
    int i,j,ii,jj,a,b,min=10000,cnt;
    bool bo=0;
    memset(g,0,sizeof(g));
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        a++;b++;
        g[a][b]=1;
        bo+=check(a,b);
        bo+=check(a+1,b);
        bo+=check(a-1,b);
        bo+=check(a,b+1);
        bo+=check(a,b-1);
        bo+=check(a+1,b+1);
        bo+=check(a+1,b-1);
        bo+=check(a-1,b+1);
        bo+=check(a-1,b-1);
        if(bo)break;
    }
    if(bo)printf("%d\n",i+1);
    else puts("-1");
    return 0;
}
