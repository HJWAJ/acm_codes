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
int main()
{
    double x1,y1,r1,x2,y2,r2;
    double dis;
    scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&x2,&y2,&r2);
    dis=sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
    dis-=r1;
    dis-=r2;
    if(dis<0)puts("0");
    else printf("%.16lf\n",dis/2.0);
	return 0;
}
