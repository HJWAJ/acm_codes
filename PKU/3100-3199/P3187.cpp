#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int i,j,a[11],b1[11],b2[11];
	for(i=0;i<n;i++)b1[i]=a[i]=i+1;
	while(1)
    {
	    for(i=0;i<n;i++)b1[i]=a[i];
	    for(j=0;j<n-1;j++)
        {
            for(i=0;i<n-j-1;i++)b2[i]=b1[i]+b1[i+1];
	        for(i=0;i<n-j-1;i++)b1[i]=b2[i];
	    }
	    if(b1[0]==k) 
        {
	        for(i=0;i<n-1;i++)printf("%d ",a[i]);
	        printf("%d\n",a[n-1]);
	        break;
        }
        next_permutation(a,a+n);
	};
	system("pause");
	return 0;
}
