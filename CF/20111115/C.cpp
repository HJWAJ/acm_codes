#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
char s[9][15][15];
void dfs(int x,int y,int dep)
{
    if(dep==end)
    {
        flag=1;
        return;
    }
    if(str[dep][x][y]=='S')return;
    int x1,y1,i;
    for(i=0;i<9;i++)
    {
        x1=x+dx[i];
        y1=y+dy[i];
        if(!ok(x1,y1))continue;
        if(str[dep][x1][y1]=='S')continue;
        dfs(x1,y1,dep+1);
    }
}
int main()
{
    int i;
    for(i=0;i<8;i++)scanf("%s",s[i]);
    dfs(7,0,0);
    if(flag)puts("WIN");
    else puts("LOSE");
    return 0;
}
