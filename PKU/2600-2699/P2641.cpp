#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const double PI=acos(-1.0);

int main()
{
	int a,b,s,m,n;
	while(scanf("%d%d%d%d%d",&a,&b,&s,&m,&n) && (a||b||s||m||n))
        printf("%.2lf %.2lf\n",atan((double)b*n/a/m)*180/PI,(double)m*a/s/cos(atan((double)b*n/a/m)));

    return 0;
}
