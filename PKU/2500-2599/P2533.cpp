#include<iostream>
using namespace std;

int main()
{
    int a[1001],b[1001],i,j,k,n;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    k=1;
    b[1]=a[1];
    for(i=2;i<=n;i++)
    {
	    if(a[i]>b[k]) b[++k]=a[i];
	    else
        {
		    j=k;
		    while(a[i]<=b[j]) j--;
		    b[j+1]=a[i];
		}
	}
    cout<<k<<endl;
    
    system("pause");
    return 0;
}
