#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char m[21][21];
bool val[26];
int dirt[4][2]={0,1,0,-1,1,0,-1,0};
int maxi;

void dfs(int r,int s,int x,int y,int n)
{
    int i;
    for(i=0;i<4;i++)
    {
        int xx=x+dirt[i][0];
        int yy=y+dirt[i][1];
        if(xx>=0 && xx<r && yy>=0 && yy<s && !val[m[xx][yy]-'A'])
        {
            val[m[xx][yy]-'A']=1;
            dfs(r,s,xx,yy,n+1);
        }
    }
    if(n>maxi)maxi=n;
    val[m[x][y]-'A']=0;
}

int main()
{
    maxi=0;
    memset(val,0,sizeof(val));
    int r,s;
    scanf("%d%d",&r,&s);
    int i,j;
    for(i=0;i<r;i++)scanf("%s",m[i]);
    val[m[0][0]-'A']=1;
    dfs(r,s,0,0,1);
    printf("%d\n",maxi);
    
    //system("pause");
    return 0;
}
