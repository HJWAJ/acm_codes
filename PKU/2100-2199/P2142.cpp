#include<iostream>
#include<cstdio>
using namespace std;

void f(const int &a,const int &b,const int &d,int &x,int &y)
{
	x=y=0;
	while(1)
	{
		if(a*x<b*y+d)
		{
			if(y==0 && (d-a*x)%b==0)
			{
				y=(d-a*x)/b;
				break;
			}
			x++;
			continue;
		}
		if(a*x==b*y+d)break;
		else y++;
	}
}

int main()
{
	int a,b,d,ax,bx,ay,by;
	while(scanf("%d%d%d",&a,&b,&d) && (a || b || d))
	{
		f(a,b,d,ax,bx);
		f(b,a,d,by,ay);
		if(ax+bx<ay+by || ((ax+bx==ay+by) && a*ax+b*bx<a*ay+b*by))printf("%d %d\n",ax,bx);
		else printf("%d %d\n",ay,by);
	}
	
	return 0;
}
