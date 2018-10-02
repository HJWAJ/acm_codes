#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int n,e;
	double l1,l2,a;
	scanf("%d%d",&n,&e);
	l1=l2=0;
	n--;e--;
	while(n--){scanf("%lf",&a);l1+=a;}
	while(e--){scanf("%lf",&a);l2+=a;}
	l1=sqrt(l1*l1+l2*l2);
	printf("%.0lf\n",ceil(l1));
	
	return 0;
}
