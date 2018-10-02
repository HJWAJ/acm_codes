#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
int main()
{
    double a,b,m,x,y,z,xx,zz,k,ansx,ansz;
    int flag=0;
    scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&m,&x,&y,&z);
    xx=-m/y*x;
    zz=-m/y*z;
    if(xx<0)
    {
        flag=1;
        xx=-xx;
    }
    if(xx<a/2)ansx=a/2+xx;
    else
    {
        xx-=a/2;
        k=floor(xx/(2*a));
        xx-=k*2*a;
        if(xx>a)ansx=xx-a;
        else ansx=a-xx;
    }
    k=floor(zz/(2*b));
    zz-=k*2*b;
    if(zz>b)ansz=2*b-zz;
    else ansz=zz;
    if(flag)ansx=a-ansx;
    printf("%.16lf %.16lf\n",ansx,ansz);
    return 0;
}
