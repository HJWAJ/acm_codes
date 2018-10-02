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
int main()
{
    __int64 x,y,m;
    __int64 cnt=0;
    scanf("%I64d%I64d%I64d",&x,&y,&m);
    if(x<=0 && y<=0 && x<m && y<m)puts("-1");
    else if(x>=m || y>=m)puts("0");
    else
    {
        if(x>y)swap(x,y);
        if(x<0)
        {
            cnt-=x/y;
            x%=y;
            cnt++;
            x+=y;
        }
        while(x<m && y<m)
        {
            if(x<y)x+=y;
            else y+=x;
            cnt++;
        }
        printf("%I64d\n",cnt);
    }
    return 0;
}
