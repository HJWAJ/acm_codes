#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int g[2005][2005];
int num[2005];
int mm=0;
void dfs(int st,int cnt)
{
    if(cnt>mm)mm=cnt;
    for(int i=0;i<num[st];i++)
        dfs(g[st][i],cnt+1);
}
int main()
{
    memset(g,0,sizeof(g));
    memset(num,0,sizeof(num));
    int n,i,j,tmp,cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        if(tmp==-1)g[0][num[0]++]=i+1;
        else g[tmp][num[tmp]++]=i+1;
    }
    /*/
    for(i=0;i<n;i++){cout<<i<<' '<<num[i]<<' ';
        for(j=0;j<num[i];j++)
            cout<<g[i][j]<<' ';
            cout<<endl;}
            //*/
    dfs(0,cnt);
    printf("%d\n",mm);
    return 0;
}
