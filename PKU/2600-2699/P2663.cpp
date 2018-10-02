#include<iostream>
using namespace std;

int main()
{
    long long int a[16],n,i;
    a[0]=1;a[1]=3;
    for(i=2;i<16;i++)a[i]=4*a[i-1]-a[i-2];
    while(cin>>n && n!=-1)
    {
        if(n&1)cout<<0<<endl;
        else cout<<a[n/2]<<endl;
    }    
    
    return 0;
}
