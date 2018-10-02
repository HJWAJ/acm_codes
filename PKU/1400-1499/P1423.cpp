#include<iostream>
#include<cmath>
#define e 2.71828182845
#define pi 3.1415926535898
using namespace std;

int main()
{
	long long int n,t;
	cin>>t;
	while(t>0)
	{
		t--;
		cin>>n;
		long long int ans=(long long int)((double)log10(sqrt(2*pi*n))+n*log10(n/e))+1;
		cout<<ans<<endl;
	}
	return 0;
}
