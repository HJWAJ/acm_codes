#include<iostream>
using namespace std;

__int64 m;
int n,a[100],b[100];

int main()
{
	char x[100];
	int tt,test,i,j;
	scanf("%d",&test);
	for (tt=1;tt<=test;tt++) 
    {
		scanf("%d",&n);
		if (n>0) scanf("%s",x);
		for (i=n-1;i>=0;i--) 
        {
			if (x[i]=='p') a[n-1-i]=1;
			else a[n-1-i]=-1;
		}
		scanf("%I64d",&m);
		for (i=0;i<n;i++)
        { 
			if (m%2!=0) 
            {
				m=(m-a[i])/2;
				b[i]=1;
			}
			else 
            {
				b[i]=0;
				m=m/2;
			}
        }
		if (m!=0) printf("Impossible\n");
		else 
        {
			j=n-1;
			for (i=j;i>=0;i--)
				printf("%d",b[i]);
			printf("\n");
		}
	}
	system("pause");
	return 0;
}

