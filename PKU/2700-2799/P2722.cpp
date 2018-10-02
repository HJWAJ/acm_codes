#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
    int i,n;
    double s,theta,x1,y1,x2,y2,a,b,c,b1,c1,l,ss,tmp;
    while(scanf("%d",&n) && n)
    {
        ss=a=0;
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        for(i=0;i<n;i++)
        {
            scanf("%lf",&l);
            a+=l;
            ss+=(l*l/2.0);
        }
        b=y1/x1;
        c=y2/x2;
        b1=1.0/(1.0+b)-1.0/(1.0+c);
        c1=b/(1.0+b)-c/(1.0+c);
        tmp=sqrt(b1*b1+c1*c1);
        s=a*a/sqrt(2.0)/tmp;
        s-=ss;
        printf("%.3lf\n",s);
    }
    
    return 0;
}
