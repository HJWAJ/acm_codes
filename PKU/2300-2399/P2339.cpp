#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
int dir[4][2]={-1,0,1,0,0,1,0,-1};
char s[105][105],tmp[105][105];
int cmp(char a,char b)
{
    if(a==b)return 0;
    if(a!='R' && a!='S' && a!='P')return -1;
    if(b!='R' && b!='S' && b!='P')return 1;
    if(a=='R' && b=='S')return 1;
    if(b=='R' && a=='S')return -1;
    if(a=='S' && b=='P')return 1;
    if(a=='P' && b=='S')return -1;
    if(a=='P' && b=='R')return 1;
    if(a=='R' && b=='P')return -1;
    return 0;
}
int main()
{
    int t,r,c,day,i,j,k;
    bool flag=0;
    scanf("%d",&t);
    while(t--)
    {
        if(flag)puts("");
        flag=1;
        scanf("%d%d%d",&r,&c,&day);
        for(i=1;i<=r;i++)scanf("%s",s[i]+1);
        while(day--)
        {
            for(i=1;i<=r;i++)
                for(j=1;j<=c;j++)
                {
                    for(k=0;k<4;k++)
                        if(cmp(s[i][j],s[i+dir[k][0]][j+dir[k][1]])<0)
                        {
                            tmp[i][j]=s[i+dir[k][0]][j+dir[k][1]];
                            break;
                        }
                    if(k==4)tmp[i][j]=s[i][j];
                }
            memmove(s,tmp,sizeof(s));
            //for(i=1;i<=r;i++)puts(s[i]+1);
        }
        for(i=1;i<=r;i++)puts(s[i]+1);
    }
    return 0;
}
