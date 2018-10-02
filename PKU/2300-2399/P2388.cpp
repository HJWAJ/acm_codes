#include<iostream>
using namespace std;

int main()
{
    int n,a[10001];
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    for(int i=0;i<n-1;i++)
       for(int j=0;j<n-1-i;j++)    
           if(a[j]<a[j+1])swap(a[j],a[j+1]);
    
    if(n%2==0)  cout<<a[n/2];
    else cout<<a[(n-1)/2];
    
    system("pause");
    return 0;
}
