#include<iostream>
using namespace std;

int main()
{
	int n,a,b,c,d,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("Scenario #%d:\n",i);
		printf("%d\n\n",(a+b+c+d)%2);
	}
	
    system("pause");
    return 0;
}

