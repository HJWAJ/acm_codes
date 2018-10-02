#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void dfs(char s[15][15][15],bool val[15][15][15],int h,int m,int n,int x,int y,int z)
{
    if(x<0 || y<0 || z<0 ||x>=m || y>=n || z>=h || s[z][x][y]!='.')return;
    s[z][x][y]='#';
    val[z][x][y]=1;
    dfs(s,val,h,m,n,x,y,z+1);
    dfs(s,val,h,m,n,x,y,z-1);
    dfs(s,val,h,m,n,x,y+1,z);
    dfs(s,val,h,m,n,x,y-1,z);
    dfs(s,val,h,m,n,x+1,y,z);
    dfs(s,val,h,m,n,x-1,y,z);     
}

int main()
{
    int h,m,n,i,j,k,cnt,x,y;
    char s[15][15][15];
    bool val[15][15][15];
    while(scanf("%d%d%d",&h,&m,&n)!=EOF)
    {
        memset(val,0,sizeof(val));
        cnt=0;
        for(i=0;i<h;i++)
            for(j=0;j<m;j++)
                scanf("%s",s[i][j]);
        scanf("%d%d",&x,&y);
        dfs(s,val,h,m,n,x-1,y-1,0);
        for(i=0;i<h;i++)
            for(j=0;j<m;j++)
                for(k=0;k<n;k++)
                    if(val[i][j][k])cnt++;
        printf("%d\n",cnt);                                    
    }    
    
    return 0;
}
