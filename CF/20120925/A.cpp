#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
#include<ctime>
using namespace std;
const double eps=1e-8;
struct point
{
    double x,y;
};
double xmult(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int main()
{
    point a,b,c;
    double res;
    scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
    res=xmult(a,c,b);
    if(fabs(res)<eps)puts("TOWARDS");
    else if(res<-eps)puts("LEFT");
    else puts("RIGHT");
    return 0;
}
