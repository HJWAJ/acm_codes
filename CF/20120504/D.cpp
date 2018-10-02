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
        printf("0.0 0.0 0.0\n");
    }
    else
    {
        x=s/(a+b+c)*a;
        y=s/(a+b+c)*b;
        z=s/(a+b+c)*c;
        printf("%.16lf %.16lf %.16lf\n",x,y,z);
    }
    return 0;
}
