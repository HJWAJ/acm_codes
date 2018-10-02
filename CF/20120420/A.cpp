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
using namespace std;
char s[105][105];
bool is(int i,int j,int x[],int y[])
{
    x[3]=i;y[3]=j;
    int xx[4],yy[4];
    memcpy(xx,x,16);
    memcpy(yy,y,16);
    sort(xx,xx+4);
    sort(yy,yy+4);
    if(xx[0]==xx[1] && xx[2]==xx[3] && yy[0]==yy[1] && yy[2]==yy[3])return 1;
    return 0;
}
int main()
{
    int i,j,n,m,cnt;
    int x[4],y[4];
    cnt=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            if(s[i][j]=='*')
            {
                x[cnt]=i;
                y[cnt]=j;
                cnt++;
            }
        }
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(is(i,j,x,y))
            {
                printf("%d %d\n",i+1,j+1);
                break;
            }
    return 0;
}
