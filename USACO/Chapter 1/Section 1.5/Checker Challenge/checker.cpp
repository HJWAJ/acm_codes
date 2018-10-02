/*
ID: hjw00002
PROG: checker
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

int n,m,mask,ans=0,step[100];
void dfs(int row,int left,int right,int index,int c)
{
    int pos,p;
    if(c==n)
    {
        ans++;
        if(ans<=3)
        {
            for(int i=0;i<c-1;i++)printf("%d ",step[i]);
            printf("%d\n",step[c-1]);
        }
    }
    else
    {
        if(index<=n)
        {
            if(c+n-index>=n)dfs(row,(left>>1),(right<<1),index+1,c);
            pos=mask&~(row|left|right);
            while(pos)
            {
                p=pos&(-pos);
                pos=pos-p;
                if(ans<=2)step[c]=(int)log2(double(p))+1;
                dfs(row+p,(left+p)>>1,(right+p)<<1,index+1,c+1);
            }
        }
    }
}

int main()
{
    freopen("checker.in","r",stdin);
    freopen("checker.out","w",stdout);
    int i,j,t,T,x,y,sum,index;
    scanf("%d",&n);
    mask=(1<<(n))-1;
    dfs(0,0,0,1,0);
    printf("%d\n",ans);
    //system("pause");
    return 0;
}
