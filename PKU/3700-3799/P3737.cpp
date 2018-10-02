#include<iostream>
#include<cmath>
#define pi 3.141592653589
using namespace std;

int main()
{
 	double s;
	while(scanf("%lf",&s)!=EOF)
    {
        double h=sqrt(s*2/pi);
        double r=sqrt(s*s/(pi*pi*h*h+pi*s*2));
        double cir=pi*r*r;
        double v=cir*h/3.0;
        printf("%.2lf\n%.2lf\n%.2lf\n",v,h,r);
    }
	
	system("pause");
	return 0;
}
