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
struct point
{
    double x,y;
}pnt[105];
const double PI=acos(-1.0);
double dis(point p1,point p2)
{
    return sqrt( (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) );
}
int main()
{
    int n,i;
    double r,l;
    while(scanf("%d%lf",&n,&r)!=EOF)
    {
        for(i=0;i<n;i++)scanf("%lf%lf",&pnt[i].x,&pnt[i].y);
        pnt[n]=pnt[0];
        l=2.0*PI*r;
        for(i=0;i<n;i++)l+=dis(pnt[i],pnt[i+1]);
        printf("%.2lf\n",l);
    }
    return 0;
}
