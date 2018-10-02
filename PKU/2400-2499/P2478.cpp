#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxp=1000001;
int p[maxp];
__int64 ans[maxp];

void prime()
{
	int i,j;
	for(i=2;i<maxp;i++)
	{
		if(!p[i])
		{
			for(j=i;j<maxp;j+=i)
			{
				if(!p[j])p[j]=j;
				p[j]=p[j]/i*(i-1);
			}
		}
	}
}
int main()
{
	int i,n;
	prime();
	for(i=1;i<maxp;i++)ans[i]=ans[i-1]+p[i];
	while(scanf("%d",&n) && n!=0)printf("%I64d\n",ans[n]);
	
    return 0;
}
