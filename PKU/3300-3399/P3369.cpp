#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    //freopen("1.txt","w",stdout);
    int a,b,c,d,s,p;
	for(a=1;a<=158;a++)
		for(b=a;b<=(2000-a)/3;b++)
			for(c=b;c<=(2000-a-b)/2;c++)
			{
				s=1000000*(a+b+c);
				p=a*b*c-1000000;
				if(p<=0 || s%p!=0)continue;
				d=s/p;
				if(d>=c && a+b+c+d<=2000)
                    printf("%.2lf %.2lf %.2lf %.2lf\n",a/100.0,b/100.0,c/100.0,d/100.0);
			}
	return 0;
}
