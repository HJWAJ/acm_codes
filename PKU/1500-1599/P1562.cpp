#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void dfs(char s[101][101],int x,int y,int m,int n)
{
    if(s[x][y]!='@' || x<0 || y<0 || x>=m || y>=n)return;
    s[x][y]='*';
    dfs(s,x-1,y-1,m,n);
    dfs(s,x-1,y,m,n);
    dfs(s,x-1,y+1,m,n);
    dfs(s,x,y-1,m,n);
    dfs(s,x,y+1,m,n);
    dfs(s,x+1,y-1,m,n);
    dfs(s,x+1,y,m,n);
    dfs(s,x+1,y+1,m,n);     
}

int main()
{
    int m,n,i,j,cnt;
    char s[101][101];
    while(scanf("%d%d",&m,&n) && !(m==0 && n==0))
    {
        cnt=0;
        for(i=0;i<m;i++)scanf("%s",s[i]);
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                if(s[i][j]=='@')
                {
                    dfs(s,i,j,m,n);
                    cnt++;                
                }         
        printf("%d\n",cnt);                 
    }    
    
    return 0;
}
