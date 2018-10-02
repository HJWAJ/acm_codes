#include<iostream>
#include<algorithm>
#define MAX 302
using namespace std;

int a[MAX],temp[MAX];

int main()
{
	int t,n,i,j;
	cin>>t;
	while(t--)
	{
		bool flag=true;
		cin>>n;
		for(i=0;i<n;i++)cin>>a[i];
		if(n==1)
		{
			cout<<1<<endl;
			flag=false;
		}
		if(flag)
		{
			for(j=1;;j++)
			{
				for(i=0;i<n;i++)temp[i]=a[i]%j;
				sort(temp,temp+n);
				for(i=1;i<n;i++)
					if(temp[i-1]==temp[i])break;
				if(i==n)break;
			}
			cout<<j<<endl;
		}
	}
	
	return 0;
}
