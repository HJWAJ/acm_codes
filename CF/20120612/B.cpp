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
#include<windows.h>
using namespace std;
char s[3005][3005];
int n,m;
void dfs(int x,int y)
{
    if(s[x][y]=='S')
    {
        puts("Yes");
        exit(0);
    }
    s[x][y]='#';
    if(x>0 && s[x-1][y]!='#')dfs(x-1,y);
    if(y>0 && s[x][y-1]!='#')dfs(x,y-1);
    if(x<2*n-1 && s[x+1][y]!='#')dfs(x+1,y);
    if(y<2*m-1 && s[x][y+1]!='#')dfs(x,y+1);
}
int main()
{
    int x,y,i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%s",s[i]);
        strncpy(s[i]+m,s[i],m);
    }
    for(i=0;i<n;i++)strcpy(s[i+n],s[i]);
    //for(i=0;i<2*n;i++)puts(s[i]);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(s[i][j]=='S')
            {
                x=i;
                y=j;
                s[x][y]='.';
                goto label;
            }
    label:;
    dfs(x,y);
    puts("No");
    return 0;
}
