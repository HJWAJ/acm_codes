#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	double a,b;
	scanf("%lf%lf",&a,&b);
	printf("%.2lf\n",b-a);
	while(1)
    {
		a=b;
		scanf("%lf",&b);
		if(b-999<0.00001 && 999-b<0.00001)
        {
			printf("End of Output\n");
			break;
		}
		printf("%.2lf\n",b-a);
	}
	return 0;
}

