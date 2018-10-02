#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int dfs(int x,int y,char s[21][300],int m,int n)
{
    if(x<0 || x>n-1 || y<0 || y>m-1 || s[x][y]!='.')return 0;
	s[x][y]='#';
	return 1+dfs(x-1,y,s,m,n)+dfs(x+1,y,s,m,n)+dfs(x,y-1,s,m,n)+dfs(x,y+1,s,m,n);    
}

int main()
{
    int m,n,i,j,x,y,ans;
    char s[21][300];
    while(scanf("%d%d",&m,&n) && !(m==0 && n==0))
    {
        for(i=0;i<n;i++)scanf("%s",s[i]);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(s[i][j]=='@')
                {
                    s[i][j]='.';
                    x=i;
                    y=j;
                    break;                
                }         
        ans=dfs(x,y,s,m,n);
        printf("%d\n",ans);             
    }    
    
    return 0;
}
