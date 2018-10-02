/*
ID: hjw00002
PROG: castle
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

int n,m,map[100][100];
bool val[200][200];
int max1=0,max2=0;

int max(int a,int b)
{
    return a>b?a:b;    
}

void dfs(int x,int y,int &cnt)
{
    val[x][y]=0;cnt++;
    if(val[x][y-1] && map[x][y]%2==0)dfs(x,y-1,cnt);
    if(val[x-1][y] && map[x][y]%4/2==0)dfs(x-1,y,cnt);
    if(val[x][y+1] && map[x][y]%8/4==0)dfs(x,y+1,cnt);
    if(val[x+1][y] && map[x][y]/8==0)dfs(x+1,y,cnt);
}

int main()
{
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    int i,j,ii,jj,iii,jjj,cnt,total=0,xx,yy;
    char p;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&map[i][j]);
            val[i][j]=1;
        }
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(val[i][j])
            {
                total++;cnt=0;
                dfs(i,j,cnt);
                max1=max(max1,cnt);
            }
            
    for(jj=1;jj<=n;jj++)
    {
        for(ii=m;ii>=1;ii--)
        {
            for(i=1;i<=m;i++)
                for(j=1;j<=n;j++)
                    val[i][j]=1;
            if(ii!=1)
            {
                if(map[ii][jj]%4/2!=0)
                {
                    map[ii][jj]-=2;
                    cnt=0;
                    dfs(ii,jj,cnt);
                    if(max2<cnt)
                    {
                        max2=cnt;
                        p='N';
                        xx=ii;
                        yy=jj;                
                    }
                    map[ii][jj]+=2;
                }         
            }
        }
        for(ii=m;ii>=1;ii--)
        {
            for(i=1;i<=m;i++)
                for(j=1;j<=n;j++)
                    val[i][j]=1;
            if(jj!=n)
            {
                if(map[ii][jj]%8/4!=0)
                {
                    map[ii][jj]-=4;
                    cnt=0;
                    dfs(ii,jj,cnt);
                    if(max2<cnt)
                    {
                        max2=cnt;
                        p='E';
                        xx=ii;
                        yy=jj;
                    }
                    map[ii][jj]+=4;
                }         
            }
        }
    }
    printf("%d\n%d\n%d\n%d %d %c\n",total,max1,max2,xx,yy,p);
    
    //system("pause");
    return 0;
}
