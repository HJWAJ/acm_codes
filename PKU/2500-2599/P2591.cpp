#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int f[10000001];

int main()
{
	int n,i;
	int x2=1,x3=1;
	f[x2]=1;
	f[x3]=1;
	for(i=2;i<=10000000;i++)
	{
		f[i]=min(f[x2]*2+1,f[x3]*3+1);
		if(f[i]==f[x2]*2+1)x2++;
		if(f[i]==f[x3]*3+1)x3++;
	}
	while(scanf("%d",&n)!= EOF)printf("%d\n",f[n]);
		
	return 0;
}
