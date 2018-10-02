#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void dfs(char s[25][25],bool val[25][25],int m,int n,int x,int y)
{
    if(x<0 || y<0 ||x>=m || y>=n || s[x][y]!='X')return;
    s[x][y]='.';
    val[x][y]=1;
    dfs(s,val,m,n,x-1,y);
    dfs(s,val,m,n,x-1,y-1);
    dfs(s,val,m,n,x+1,y);
    dfs(s,val,m,n,x+1,y-1);
    dfs(s,val,m,n,x,y-1);
    dfs(s,val,m,n,x-1,y+1);
    dfs(s,val,m,n,x,y+1);
    dfs(s,val,m,n,x+1,y+1);     
}

int solve(bool val[25][25],int m,int n)
{
    int cnt=0,i,j;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            if(val[i][j])
            {
                cnt+=4;
                if(i>0)
                    if(val[i-1][j])cnt--;
                if(j>0)
                    if(val[i][j-1])cnt--;
                if(i<m-1)
                    if(val[i+1][j])cnt--;
                if(j<n-1)
                    if(val[i][j+1])cnt--;             
            }                
        }
    return cnt;
}

int main()
{
    int m,n,x,y,i,j,length;
    char s[25][25];
    bool val[25][25];
    while(scanf("%d%d%d%d",&m,&n,&x,&y) && !(m==0 && n==0 && x==0 && y==0))
    {
        x--;y--;
        for(i=0;i<m;i++)scanf("%s",s[i]);
        memset(val,0,sizeof(val));
        dfs(s,val,m,n,x,y);
        length=solve(val,m,n);
        printf("%d\n",length);                                    
    }
    
    return 0;
}
