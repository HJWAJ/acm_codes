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
const double pi=acos(-1.0);
double gcd(double a,double b)
{
    if(b<0.01)return a;
    return gcd(b,fmod(a,b));
}
double dis(double x1,double y1,double x2,double y2)
{
    return  (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ;
}
double getcos(double x1,double y1,double x2,double y2,double x3,double y3)
{
    double d1=dis(x1,y1,x2,y2),d2=dis(x1,y1,x3,y3),d3=dis(x3,y3,x2,y2);
    return acos(  (d1+d2-d3) / 2 / sqrt(d1 * d2 ) );
}
int main()
{
    double x1,x2,x3,y1,y2,y3,a,b,c,d;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
        a=getcos(x1,y1,x2,y2,x3,y3);
        b=getcos(x2,y2,x3,y3,x1,y1);
        c=getcos(x3,y3,x2,y2,x1,y1);
        a=a/pi*180;
        b=b/pi*180;
        c=c/pi*180;
        //printf("abc: %.4lf %.4lf %.4lf\n",a,b,c);
        d=gcd(gcd(a,b),c);
        //printf("d: %.4lf\n",d);
        printf("%d\n",(int)(180/d));
    }
    return 0;
}
