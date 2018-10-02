#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int t,a[3];
    cout<<"Gnomes:"<<endl;
    cin>>t;
    while(t--)
    {
         cin>>a[0]>>a[1]>>a[2];
         if((a[0]>=a[1] && a[1]>=a[2]) || (a[0]<=a[1] && a[1]<=a[2]))cout<<"Ordered"<<endl;
         else cout<<"Unordered"<<endl;         
    }
    
    system("pause");
    return 0;
}
