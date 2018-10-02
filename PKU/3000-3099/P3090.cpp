#include<iostream>
#include<cstdio>
int main()
{
	int i,j,n,f[1001];
	f[0]=f[1]=0;
	for(i=2;i<=1000;i++)
    {
		f[i]=i*(i-1)/2;
		for(j=2;j<=i/2;j++)
			f[i]-=f[i/j];
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
		scanf("%d",&j);
		printf("%d %d %d\n",i,j,f[j]*2+3);
	}
	system("pause");
	return 0;
}

