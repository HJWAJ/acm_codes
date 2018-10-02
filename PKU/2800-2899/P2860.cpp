#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int N,M,K,count,a[21],i;
	scanf("%d%d%d",&N,&M,&K);
	for(i=0;i<2*K;i++)scanf("%d",&a[i]);
	count=0;
	for(i=0;i<K;i++)
		if(a[i]<a[i+K])
			count+=(a[i+K]-a[i]);
	printf("%d\n",count);
	
    return 0;
}
