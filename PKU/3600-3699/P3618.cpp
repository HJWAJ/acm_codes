#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

struct point
{
    int a,b;       
}p[50000];

int cmp(const void *p1,const void *p2)
{
    point *aa=(point *)p1;
    point *bb=(point *)p2;
    return aa->b - bb->b;
}

int main()
{
    int t,n,flag=0,cnt=0,i;
    scanf("%d%d",&t,&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i].a);
        p[i].b=abs(p[i].a);
    }
    qsort(p,n,sizeof(p[0]),cmp);
    i=0;
    while(t>0)
	{
		if(abs(flag-p[i].a)>t)break;
		t-=abs(flag-p[i].a);
		flag=p[i].a;
		i++;
		cnt++;
	}
	printf("%d\n",cnt);
    
    return 0;
}
