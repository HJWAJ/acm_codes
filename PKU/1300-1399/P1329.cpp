#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
    double x1,y1,x2,y2,x3,y3,d,e,f,x0,y0,r,rr;
    char p[5];
    while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
    {
        d=((x2*x2+y2*y2-x1*x1-y1*y1)*(y1-y3)-(x3*x3+y3*y3-x1*x1-y1*y1)*(y1-y2))/((x1-x2)*(y1-y3)-(x1-x3)*(y1-y2));
        e=((x2*x2+y2*y2-x1*x1-y1*y1)*(x1-x3)-(x3*x3+y3*y3-x1*x1-y1*y1)*(x1-x2))/((y1-y2)*(x1-x3)-(y1-y3)*(x1-x2));
        f=-(x1*x1+y1*y1+d*x1+e*y1);
        x0=d/2.0;
        y0=e/2.0;
        rr=d*d/4.0+e*e/4.0-f;
        r=sqrt(rr);
        p[0]=p[2]=x0>=0?'+':'-';
        p[1]=p[3]=y0>=0?'+':'-';
        p[4]=f>0?'+':'-';
        d=fabs(d);
        e=fabs(e);
        f=fabs(f);
        x0=fabs(x0);
        y0=fabs(y0);
        printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n",p[0],x0,p[1],y0,r);
        printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n\n",p[2],d,p[3],e,p[4],f);
    }    
    
    return 0;
}
