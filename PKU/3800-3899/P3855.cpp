#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;

double dis(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));       
}

bool isni(int x1,int y1,int x2,int y2,int x3,int y3)
{
    if((x3-x1)*(y2-y1)<(x2-x1)*(y3-y1))return 1;
    return 0;
}

int main()
{
    int n,t=0,x[105],y[105],i;
    double s[105],x0,y0,a,b,c,p,xx[105],yy[105],ss;
    while(scanf("%d",&n) && n)
    {
        t++;
        for(i=0;i<n;i++)scanf("%d%d",&x[i],&y[i]);
        x0=y0=ss=0;
        for(i=0;i<n-2;i++)
        {
            a=dis(double(x[0]),double(y[0]),double(x[i+1]),double(y[i+1]));
            b=dis(double(x[0]),double(y[0]),double(x[i+2]),double(y[i+2]));
            c=dis(double(x[i+2]),double(y[i+2]),double(x[i+1]),double(y[i+1]));
            p=(a+b+c)/2;
            s[i]=sqrt(p*(p-a)*(p-b)*(p-c));
            if(isni(x[0],y[0],x[i+1],y[i+1],x[i+2],y[i+2]))s[i]=-s[i];
            ss+=s[i];
            xx[i]=double(x[0]+x[i+1]+x[i+2])/3.0;
            yy[i]=double(y[0]+y[i+1]+y[i+2])/3.0;
            x0+=xx[i]*s[i];
            y0+=yy[i]*s[i];                  
        }
        x0/=ss;
        y0/=ss;
        printf("Stage #%d: %.6lf %.6lf\n",t,x0,y0);                     
    }    
    return 0;
}
