#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const double PI=3.141592653589;

int main()
{
    int D,dv;
    double R,r,d,v,v1,v2,v3;
    while(scanf("%d%d",&D,&dv) && !(D==0 && dv==0))
    {
        R=D/2.0;
        v=PI*R*R*D;
        v1=PI*R*R*D/3.0;
        r=pow(3.0*(v-v1-dv)/4.0/PI,1.0/3.0);
        d=2.0*r;
        printf("%.3lf\n",d);                       
    }
    
    return 0;
}
