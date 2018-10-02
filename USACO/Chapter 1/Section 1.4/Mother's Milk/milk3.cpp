/*
ID: hjw00002
PROG: milk3
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

bool val[21][21][21];
bool flag[21];
int aa,bb,cc;

int min(int m,int n)
{
    return m<n?m:n;    
}

void dfs(int a,int b,int c)
{
    if(val[a][b][c])return;
    int sub;
    val[a][b][c]=1;
    sub=min(a+b,bb)-b;
    if(sub>0)dfs(a-sub,b+sub,c);
    sub=min(a+b,aa)-a;
    if(sub>0)dfs(a+sub,b-sub,c);
    sub=min(a+c,cc)-c;
    if(sub>0)dfs(a-sub,b,c+sub);
    sub=min(a+c,aa)-a;
    if(sub>0)dfs(a+sub,b,c-sub);
    sub=min(c+b,bb)-b;
    if(sub>0)dfs(a,b+sub,c-sub);
    sub=min(c+b,cc)-c;
    if(sub>0)dfs(a,b-sub,c+sub);
}

int main()
{
    freopen("milk3.in","r",stdin);
    freopen("milk3.out","w",stdout);
    memset(val,0,sizeof(val));
    memset(flag,0,sizeof(flag));
    scanf("%d%d%d",&aa,&bb,&cc);
    dfs(0,0,cc);
    int i,j,k;
    for(j=0;j<=bb;j++)
        for(k=0;k<=cc;k++)
            if(val[0][j][k])flag[k]=1;
    for(i=0;i<=cc;i++)
        if(flag[i]){printf("%d",i);break;}
    i++;
    for(;i<=cc;i++)
        if(flag[i])printf(" %d",i);
    printf("\n");
    
    //system("pause");
    return 0;
}
