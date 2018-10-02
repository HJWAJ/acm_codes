#include<iostream>
using namespace std;

int main()
{
    int i,n;
    int a[32768],b[32768];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];                
    }
    for(i=0;i<n;i++)
    {
        if(a[i]<b[i])cout<<"NO BRAINS"<<endl;
        else cout<<"MMM BRAINS"<<endl;                
    }
    system("pause");
    return 0;
}
