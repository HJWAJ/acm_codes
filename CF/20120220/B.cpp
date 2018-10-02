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
#include<sstream>
using namespace std;
__int64 inf=100000000000000;
int main()
{
    __int64 row,col,x,y,xx,yy,n,step,sum=0,stepx,stepy,xxx,yyy;
    scanf("%I64d%I64d%I64d%I64d%I64d",&row,&col,&x,&y,&n);
    while(n--)
    {
        scanf("%I64d%I64d",&xx,&yy);
        xxx=xx;
        yyy=yy;
        if(xx==0)stepx=inf;
        else if(xx<0)
        {
            xx=-xx;
            stepx=(x-1)/xx;
        }
        else stepx=(row-x)/xx;
        if(yy==0)stepy=inf;
        else if(yy<0)
        {
            yy=-yy;
            stepy=(y-1)/yy;
        }
        else stepy=(col-y)/yy;
        if(stepx<stepy)step=stepx;
        else step=stepy;
        sum+=step;
        x+=step*xxx;
        y+=step*yyy;
    }
    printf("%I64d\n",sum);
    return 0;
}
