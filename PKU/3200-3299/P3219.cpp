#include<iostream>
using namespace std;

int main()
{
    long long int n,k;
    while(cin>>n>>k)
    {
        if((n&k)==k)cout<<1<<endl;
        else cout<<0<<endl;                
    }
    
    system("pause");
    return 0;
}
