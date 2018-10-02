#include <iostream>
using namespace std;
bool b[4000000];
int main()
{
	int a[500001],i,j,w,n;
	for(j=0;j<4000000;j++)b[j]=0;
	a[0]=0;
	for(i=1;i<500001;i++)
	{	
		w=a[i-1]-i;
		if(a[i-1]-i>0&&b[w]==0)
		{
			a[i]=a[i-1]-i;
			b[w]=1;
		}
		else
		{
			a[i]=a[i-1]+i;
			w=a[i];
			b[w]=1;
		}
	}
	cin>>n;
	while(n!=-1)
	{
		cout<<a[n]<<endl;
		cin>>n;
	}
	system("pause");
	return 0;
}
