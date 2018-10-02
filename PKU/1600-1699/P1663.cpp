#include<iostream>
using namespace std;

int main()
{
    int n,a,b; 
    cin>>n;
    for(int i=0;i<n;i++)
     {  
        cin>>a>>b;
        
        if(a!=b && a!=b+2)cout<<"No Number"<<endl;
        else 
        {
             if(a%2==0)cout<<a+b<<endl;
             else cout<<a+b-1<<endl;
        }
    }
        
    
    system("pause");
    return 0;
}
