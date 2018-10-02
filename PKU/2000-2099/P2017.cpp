#include<iostream>
using namespace std;

int main()
{
    int n,i;
    int sum;
    int v[10000],t[10000];
    while(cin>>n && n!=-1)
    {
        sum=0;
        for(i=0;i<n;i++)cin>>v[i]>>t[i];
        sum=sum+v[0]*t[0];
        for(i=1;i<n;i++)
            sum=sum+v[i]*(t[i]-t[i-1]);
        cout<<sum<<" miles"<<endl;             
    }    
    
    system("pause");
    return 0;
}
