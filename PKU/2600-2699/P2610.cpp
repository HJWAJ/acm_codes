#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

double dis(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));       
}

int main()
{
    double x1,y1,x2,y2,x,y,d1,d2;
    int val=0;
    scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
    while(scanf("%lf%lf",&x,&y)!=EOF)
    {
        d1=dis(x1,y1,x,y);
        d2=dis(x2,y2,x,y);
        if(d2-d1*2<0.0000001)continue;
        printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",x,y);
        val=1;
        while(scanf("%lf%lf",&x,&y)==EOF)goto label;         
    }    
    label:if(val==0)printf("The gopher cannot escape.\n");
    
    //system("pause");
    return 0;
}
