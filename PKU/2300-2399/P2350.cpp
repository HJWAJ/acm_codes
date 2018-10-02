#include"iostream"
using namespace std;
int main()
{
    int i=0,n,count=0,m,j;
	float sum,ave,a[1000];
	scanf("%d",&n);
	while(i<n)
	{
		count=0;sum=0;
		i++;
		scanf("%d",&m);
		for( j=0;j<m;j++)
		{
			scanf("%f",&a[j]);
			sum+=a[j];
		}
		ave=sum/m;
		for(j=0;j<m;j++)
			if(a[j]>ave)
				count++;
			printf("%.3f%%\n",(float) count/m*100);
	}
	return 0;
}
