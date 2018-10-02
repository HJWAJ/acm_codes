#include<iostream>
using namespace std;

int main()
{
    int n,a,b,s,d;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s>>d;
        a=(s+d)/2;
        b=(s-d)/2;
        if(b>=0 && (s+d)%2==0 && (s-d)%2==0)cout<<a<<" "<<b<<endl;
        else cout<<"impossible"<<endl;        
            
    }
    
    system("pause");
    return 0;
}
