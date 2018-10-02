#include<iostream>
using namespace std;

int a[100005];

int main()
{
	int i,j,n;
	while(scanf("%d",&n) && n!=0)
	{
		int tmp=1;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=1;i<=n;i++)
            if(a[a[i]]!=i)
			{
				tmp=0;
				break;
			}
		if(tmp==0)printf("not ambiguous\n");
		else printf("ambiguous\n");
	}
	return 0;
}
