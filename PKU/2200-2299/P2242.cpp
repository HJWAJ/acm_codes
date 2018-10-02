#include<cstdio>
#include<cstring>
#include<cmath>
#define pi 3.141592653589793
using namespace std;

int main()
{
    double x1,x2,x3,y1,y2,y3,a,b,c,p,s,r,cir;
    while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
    {
        a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        b=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
        c=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
        p=(a+b+c)/2;
        s=sqrt(p*(p-a)*(p-b)*(p-c));
        r=a*b*c/s/4.0;
        cir=2*r*pi;
        printf("%.2lf\n",cir);
    }
    
    //system("pause");
    return 0;
}
