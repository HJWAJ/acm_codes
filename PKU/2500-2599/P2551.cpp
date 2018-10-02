#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int main()
{
	int s,ans,n;
	while(scanf("%d",&n)!=EOF)
	{
		s=1;
		ans=1;
		s%=n;
		while(s!=0)
		{
			s=s*10+1;
			ans++;
			s%=n;
		}
		printf("%d\n",ans);
	}
	
	system("pause");
	return 0;
}
