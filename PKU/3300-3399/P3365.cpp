#include<iostream>
#define PI 3.141592653589
using namespace std;

double max(double a,double b)
{   return a>b?a:b;}

double min(double a,double b)
{   return a<b?a:b;}

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b) && !(a==0 && b==0))
    {
        if(a<b)swap(a,b);
        double r=min(a/(2+2*PI),b/2.0);
        double v1=PI*r*r*b;
        double v2;
        r=a/3.0;
        if(r>b/PI/2.0)r=b/PI/2.0;
        v2=PI*r*r*(a-2.0*r);
        double v=max(v1,v2);
        printf("%.3lf\n",v);
    }    
    return 0;
}
