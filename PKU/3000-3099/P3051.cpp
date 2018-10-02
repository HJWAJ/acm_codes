#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
char s[1005][105];
int dfs(int x,int y)
{
    if(s[x][y]!='*')return 0;
    s[x][y]='.';
    return dfs(x-1,y)+dfs(x,y-1)+dfs(x+1,y)+dfs(x,y+1)+1;
}
int main()
{
    int w,h,i,j,max,tmp;
    while(scanf("%d%d",&w,&h)!=EOF)
    {
        max=0;
        memset(s,'.',sizeof(s));
        for(i=1;i<=h;i++)scanf("%s",s[i]+1);
        for(i=1;i<=h;i++)
            for(j=1;j<=w;j++)
                if(s[i][j]=='*')
                {
                    tmp=dfs(i,j);
                    if(max<tmp)max=tmp;
                }
        printf("%d\n",max);
    }
    return 0;
}
