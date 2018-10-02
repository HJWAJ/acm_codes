#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
#include<ctime>
//#include<windows.h>
using namespace std;
int a[10005];
int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%d",a+i);
		int sum=0;
		for(i=1;i<=n;i++)
			while(a[i]!=i)
			{
				swap(a[i],a[a[i]]);
				sum++;
			}
		printf("%d\n",sum);
	}
	return 0;
}