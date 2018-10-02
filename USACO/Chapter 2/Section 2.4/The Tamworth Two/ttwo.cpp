/*
ID: hjw00002
PROG: ttwo
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
char s[15][15];
bool bo[160005];
int dir[4][2]={-1,0,0,1,1,0,0,-1};
int main()
{
    freopen("ttwo.in","r",stdin);
    freopen("ttwo.out","w",stdout);
    int i,j,x1,y1,x2,y2,dir1=0,dir2=0,state,cnt=0;
    for(i=0;i<10;i++)scanf("%s",s[i]);
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            if(s[i][j]=='F')
            {
                x1=i;
                y1=j;
                break;
            }
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            if(s[i][j]=='C')
            {
                x2=i;
                y2=j;
                break;
            }
    memset(bo,0,sizeof(bo));
    while(1)
    {
        if(x1==x2 && y1==y2)
        {
            printf("%d\n",cnt);
            break;
        }
        state=(dir1*100+x1*10+y1)*400+dir2*100+x2*10+y2;
        if(bo[state]==1)
        {
            puts("0");
            break;
        }
        else bo[state]=1;
        if(s[x1+dir[dir1][0]][y1+dir[dir1][1]]=='*' || x1+dir[dir1][0]<0 || x1+dir[dir1][0]>9 || y1+dir[dir1][1]<0 || y1+dir[dir1][1]>9)
        {
            dir1++;
            dir1%=4;
        }
        else
        {
            x1+=dir[dir1][0];
            y1+=dir[dir1][1];
        }
        if(s[x2+dir[dir2][0]][y2+dir[dir2][1]]=='*' || x2+dir[dir2][0]<0 || x2+dir[dir2][0]>9 || y2+dir[dir2][1]<0 || y2+dir[dir2][1]>9)
        {
            dir2++;
            dir2%=4;
        }
        else
        {
            x2+=dir[dir2][0];
            y2+=dir[dir2][1];
        }
        cnt++;
    }
    return 0;
}
