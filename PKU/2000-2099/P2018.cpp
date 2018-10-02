#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int i,j,n,k,s[100005]={0},a=-1;
    scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&j);
		s[i]=s[i-1]+j;
	}
	for(i=0,j=0;i<=n-k;i++)
	{
		if((i-j)*(s[i+k]-s[j])-(i+k-j)*(s[i]-s[j])>0)j=i;
        if(a<1000*(s[i+k]-s[j])/(i+k-j))a=1000*(s[i+k]-s[j])/(i+k-j);
	}
	printf("%d\n",a);
	
	return 0;
}
