#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<set>
#include<queue>
#include<string>
#include<vector>
using namespace std;
char s[105][205];
int n;
int checkdown(int x,int y)
{
    int i,depth=0,len=1,maxlen=1,xx=x,yy=y;
    if(s[xx][yy]!='-')return 0;
    while(maxlen>=len && xx>=0 && yy>=xx && xx<n && yy<2*n-x-1)
    {
        len+=2;
        xx--;
        yy--;
        maxlen=0;
        for(i=yy;s[xx][i]=='-';i++)maxlen++;
        //if(x==0 && y==3)cout<<depth<<' '<<maxlen<<endl;
        depth++;
    }
    return depth;
}
int checkup(int x,int y)
{
    int i,depth=0,len=1,maxlen=1,xx=x,yy=y;
    if(s[xx][yy]!='-')return 0;
    while(maxlen>=len && xx>=0 && yy>=xx && xx<n && yy<2*n-x-1)
    {
        len+=2;
        xx++;
        yy--;
        maxlen=0;
        for(i=yy;s[xx][i]=='-';i++)maxlen++;
        //if(x==0 && y==3)cout<<depth<<' '<<maxlen<<endl;
        depth++;
    }
    return depth;
}
int main()
{
    int i,j,tmp,mmax,tt=0;
    while(scanf("%d",&n) && n)
    {
        tt++;
        mmax=0;
        for(i=0;i<n;i++)scanf("%s",s[i]+i);
        for(i=0;i<n;i++)
            for(j=i;j<n*2-1-i;j++)
            {
                if((j-i)&1)
                {
                    tmp=checkup(i,j);
                    if(tmp>mmax)mmax=tmp;
                }
                else
                {
                    tmp=checkdown(i,j);
                    if(tmp>mmax)mmax=tmp;;
                }
            }
        printf("Triangle #%d\nThe largest triangle area is %d.\n\n",tt,mmax*mmax);
    }
    return 0;
}
