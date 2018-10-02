#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
int main()
{
    double s,a,b,c;
    double x,y,z;
    scanf("%lf%lf%lf%lf",&s,&a,&b,&c);
    if(a+b+c==0)
    {
        printf("%.6lf %.6lf %.6lf\n",s/3.0,s/3.0,s/3.0);
        return 0;
    }
    else if(a==0)
    {
        x=0.0;
        y=1.0*b*s/(b+c);
        z=s-y;
        printf("%.6lf %.6lf %.6lf\n",x,y,z);
        return 0;
    }
    y=1.0*a*b*s/(1.0*(a+b)*(a+c)-1.0*b*c);
    z=1.0*a*c*s/(1.0*(a+b)*(a+c)-1.0*b*c);
    x=s-y-z;
    printf("%.6lf %.6lf %.6lf\n",x,y,z);
    return 0;
}
