#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int t;
    double vs,r,c,w,vr;
    scanf("%lf%lf%lf%d",&vs,&r,&c,&t);
    for(int i=0;i<t;i++)
    {
        scanf("%lf",&w);
        vr=c*r*w*vs/sqrt(1+c*r*w*c*r*w);
        printf("%.3lf\n",vr);          
    }
	system("pause");
	return 0;
}
