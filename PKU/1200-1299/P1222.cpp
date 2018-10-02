#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<fstream>
using namespace std;
int a[10][10],ans[10][10],a1[10][10];
void change(int &num)
{
    if(num)num=0;
    else num=1;
}
void press(int x,int y)
{
    ans[x][y]=1;
    change(a1[x][y]);
    if(y>0)change(a1[x][y-1]);
    if(y<5)change(a1[x][y+1]);
    if(x>0)change(a1[x-1][y]);
    if(x<4)change(a1[x+1][y]);
}
bool check()
{
    int i;
    for(i=0;i<6;i++)
        if(a1[4][i]==1)
            return 0;
    return 1;
}
int main()
{
    int t,tt=0,i,j,cnt;
    scanf("%d",&t);
    while(t--)
    {
        tt++;
        for(i=0;i<5;i++)
            for(j=0;j<6;j++)
                scanf("%d",&a[i][j]);
        for(cnt=0;cnt<64;cnt++)
        {
			memcpy(a1,a,sizeof(a));
			memset(ans,0,sizeof(ans));
			for(j=0;j<6;j++)
                if(cnt&(1<<j))press(0,j);
			for(i=1;i<5;i++)
				for(j=0;j<6;j++)
					if(a1[i-1][j])press(i,j);
			if(check())break;
		}
		printf("PUZZLE #%d\n",tt);
		for(i=0;i<5;i++)
		{
			printf("%d",ans[i][0]);
			for(j=1;j<6;j++)printf(" %d",ans[i][j]);
			printf("\n");
		}
    }
	return 0;
}
