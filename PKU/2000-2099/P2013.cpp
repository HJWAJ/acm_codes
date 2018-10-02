#include<iostream>
using namespace std;

int main()
{
    char a[1000][1000];
    int n,k=1;
    
    cin>>n;
    while(n!=0)
    {
        
        for(int i=0;i<n;i++)
        cin>>a[i];
        cout<<"SET "<<k<<endl;
        k++;
        if(n%2==0)
        {
            for(int j=0;j<n;j+=2)   cout<<a[j]<<endl;
            for(int j=n-1;j>0;j-=2)   cout<<a[j]<<endl;      
        }           
        else
        {
            for(int j=0;j<n;j+=2)   cout<<a[j]<<endl;
            for(int j=n-2;j>0;j-=2)   cout<<a[j]<<endl;
        }
        cin>>n;
    }
    
    system("pause");
    return 0;    
}
