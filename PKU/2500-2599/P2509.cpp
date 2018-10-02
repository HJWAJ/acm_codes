#include<iostream>
using namespace std;

int main()
{
    int n,k,s;
    while(cin>>n>>k)
    {s=0;
    while(n>=k)
    {
         s=s+n-n%k;
         n=n/k+n%k;           
    }
    s+=n;
    cout<<s<<endl;
    }
    system("pause");
    return 0;
}
