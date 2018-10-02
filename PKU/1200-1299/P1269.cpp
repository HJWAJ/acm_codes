#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<fstream>
using namespace std;
double t;
int main()
{
    int t,x1,x2,x3,x4,y1,y2,y3,y4,k;
	puts("INTERSECTING LINES OUTPUT");
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		x1-=x2;y1-=y2;
		x3-=x4,y3-=y4;
		k=x1*y3-y1*x3;
		if(!k)
		{
			x2-=x4;y2-=y4;
			puts(x2*y3==x3*y2?"LINE":"NONE");
		}else printf("POINT %.2lf %.2lf\n",double(x1*y2*x3-y1*x2*x3+x1*y3*x4-x1*x3*y4)/k,double(x1*y2*y3-y1*x2*y3+y1*y3*x4-y1*x3*y4)/k);
	}
	puts("END OF OUTPUT");
	return 0;
}
