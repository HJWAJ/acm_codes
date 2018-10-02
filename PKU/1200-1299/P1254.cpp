#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
	int t;
    double c=acos(0.0)/90,x,y,s,x2,y2,s2,k;
    scanf("%d",&t);
    while(t--)
    {
		scanf("%lf%lf%lf%lf%lf%lf",&x,&y,&s,&x2,&y2,&s2);
		k=((y-y2)*sin(s2*c)-(x-x2)*cos(s2*c))/(sin(s*c)*cos(s2*c)-cos(s*c)*sin(s2*c));
		printf("%.4f %.4f\n",x+k*sin(s*c),y+k*cos(s*c));
	}
	
	return 0;
}
