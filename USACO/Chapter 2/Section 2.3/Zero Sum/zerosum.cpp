/*
ID: hjw00002
PROG: zerosum
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int sum,s,t,n;
int ans[15];
int getnum(int s,int t)
{
    int res=0,i;
    for(i=s;i<=t;i++)
    {
        res*=10;
        res+=i;
    }
    return res;
}
void dfs(int cnt)
{
    int i;
    if(cnt==n)
    {
        sum=0;
        for(i=1;i<n;i++)
            if(ans[i]!=2)break;
        if(i==n)return ;
        s=t=i=1;
        while(ans[i]==2)
        {
            i++;
            t++;
        }
        sum+=getnum(s,t);
        while(1)
        {
            if(ans[i]==0)
            {
                i++;
                s=t=i;
                while(ans[i]==2 && i<n)
                {
                    i++;
                    t++;
                }
                sum+=getnum(s,t);
                if(i==n)break;
            }
            else if(ans[i]==1)
            {
                i++;
                s=t=i;
                while(ans[i]==2 && i<n)
                {
                    i++;
                    t++;
                }
                sum-=getnum(s,t);
                if(i==n)break;
            }
        }
        //cout<<sum<<endl;
        if(sum==0)
        {
            for(i=1;i<n;i++)
            {
                printf("%d",i);
                if(ans[i]==0)printf("+");
                else if(ans[i]==1)printf("-");
                else printf(" ");
            }
            printf("%d\n",n);
        }
        return ;
    }
    ans[cnt]=2;
    dfs(cnt+1);
    ans[cnt]=0;
    dfs(cnt+1);
    ans[cnt]=1;
    dfs(cnt+1);
}
int main()
{
    freopen("zerosum.in","r",stdin);
    freopen("zerosum.out","w",stdout);
    memset(ans,-1,sizeof(ans));
    scanf("%d",&n);
    dfs(1);
    return 0;
}
