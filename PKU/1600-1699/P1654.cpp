#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
	int n,i,x1,x2,y1,y2,len,p,dic[10][2]={{0,0},{1,-1},{1,0},{1,1},{0,-1},{0,0},{0,1},{-1,-1},{-1,0},{-1,1}};  //对各个字符对应的坐标值用数组先保存下来
	long long s,j;
	char a[1000100];
	scanf("%d",&n);
	while(n--)
	{
		s=0;
		scanf("%s",a);
		len=strlen(a);
		x1=0;y1=0;
		for(i=0;i<len-1;i++)
		{
			p=a[i]-'0';
			x2=x1+dic[p][0];
			y2=y1+dic[p][1];
			s+=x1*y2-y1*x2;
			x1=x2;
			y1=y2;
		}
		j=(long long)fabs((long double)s);
		if(j==0)printf("0\n");
		else
		{
			if(j%2==0)printf("%lld\n",j/2);
			else printf("%lld.5\n",j/2);
        }
	}
	return 0;
}
