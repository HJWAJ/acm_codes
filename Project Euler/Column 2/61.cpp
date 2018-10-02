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
int g[105][105];
int answer[10];
int mask=0;
void getans()
{
    int i;
    int res=0;
    for(i=0;i<6;i++)
    {
        printf("%d ",answer[i]);
        res+=answer[i]*100+answer[(i+1)%6];
    }
    printf("\n%d\n",res);
    exit(0);
}
void dfs(int x,int bits)
{
    int i,j;
    if(bits==5)
    {
        answer[5]=x;
        for(i=0;i<6;i++)
            if(!(mask&(1<<i)) && (g[x][answer[0]]&(1<<i)))
            {
                getans();
            }
        return;
    }
    for(i=10;i<100;i++)
        for(j=0;j<6;j++)
            if(!(mask&(1<<j)) && (g[x][i]&(1<<j)))
            {
                mask|=(1<<j);
                answer[bits]=x;
                //getans();
                dfs(i,bits+1);
                answer[bits]=0;
                mask&=~(1<<j);
            }
}
int main()
{
    int ans,i,j;
    int ii,jj,iii,jjj;
    memset(g,0,sizeof(g));
    for(i=1,ans=0;ans<10000;i++)
    {
        ans=i*(i+1)/2;
        if(ans%100>=10 && ans/100>=10 && ans/100<100)g[ans/100][ans%100]+=1;
    }
    for(i=1,ans=0;ans<10000;i++)
    {
        ans=i*i;
        if(ans%100>=10 && ans/100>=10 && ans/100<100)g[ans/100][ans%100]+=2;
    }
    for(i=1,ans=0;ans<10000;i++)
    {
        ans=i*(3*i-1)/2;
        if(ans%100>=10 && ans/100>=10 && ans/100<100)g[ans/100][ans%100]+=4;
    }
    for(i=1,ans=0;ans<10000;i++)
    {
        ans=i*(2*i-1);
        if(ans%100>=10 && ans/100>=10 && ans/100<100)g[ans/100][ans%100]+=8;
    }
    for(i=1,ans=0;ans<10000;i++)
    {
        ans=i*(5*i-3)/2;
        if(ans%100>=10 && ans/100>=10 && ans/100<100)g[ans/100][ans%100]+=16;
    }
    for(i=1,ans=0;ans<10000;i++)
    {
        ans=i*(3*i-2);
        if(ans%100>=10 && ans/100>=10 && ans/100<100)g[ans/100][ans%100]+=32;
    }
    for(i=10;i<100;i++)
        dfs(i,0);
    return 0;
}
