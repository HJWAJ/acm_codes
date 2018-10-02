#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
const double PI=acos(-1.0);
int main()
{
    double x1,y1,x2,y2,r1,r2,d,s,x,h,ss,alpha,beta;
    scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&x2,&y2,&r2);
    d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    if(r1<r2)
    {
        swap(x1,x2);
        swap(y1,y2);
        swap(r1,r2);
    }
    if(r1+r2<=d)s=0;//外离或外切
    else if(r1-r2>=d)s=PI*r2*r2;//内含或内切
    else if(d>=r1)//相交且小圆圆心在大圆外
    {
        x=d*d+r1*r1-r2*r2;
        x/=(d*2.0);
        h=sqrt(r1*r1-x*x);
        alpha=acos(x/r1);
        beta=acos((d-x)/r2);
        s=r1*r1*alpha+r2*r2*beta-d*h;
    }
    else//相交且小圆圆心在大圆内
    {
        x=d*d-r1*r1+r2*r2;
        x/=(d*2.0);
        x=-x;
        h=sqrt(r2*r2-x*x);
        alpha=acos((d+x)/r1);
        beta=acos(x/r2);
        s=r1*r1*alpha-(d+x)*h;
        s+=(PI-beta)*r2*r2;
        s+=x*h;
    }
    printf("%.3lf\n",s);
    return 0;
}
