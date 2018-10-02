#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
#include<stack>
#include<sstream>
using namespace std;
bool bo[55][55][55][55];
int main()
{
    int x1,x2,y1,y2,dis1,dis2,dis3,cnt=0;
    for(x1=0;x1<=50;x1++)
        for(y1=0;y1<=50;y1++)
            for(x2=0;x2<=50;x2++)
                for(y2=0;y2<=50;y2++)
                {
                    if(x1==x2 && y1==y2)continue;
                    if(x1==0 && y1==0)continue;
                    if(0==x2 && 0==y2)continue;
                    if(bo[x1][y1][x2][y2])continue;
                    bo[x1][y1][x2][y2]=1;
                    bo[x2][y2][x1][y1]=1;
                    dis1=x1*x1+y1*y1;
                    dis2=x2*x2+y2*y2;
                    dis3=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                    if(dis1+dis2==dis3 || dis1+dis3==dis2 || dis2+dis3==dis1)cnt++;
                }
    printf("%d\n",cnt);
    return 0;
}
