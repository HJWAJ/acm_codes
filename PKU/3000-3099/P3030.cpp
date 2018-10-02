#include<iostream>
using namespace std;

int main()
{
    int t,a,b,c;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        if(a+c<b)cout<<"advertise"<<endl;
        else if(a+c==b)cout<<"does not matter"<<endl;
        else cout<<"do not advertise"<<endl;          
    }
    
    system("pause");
    return 0;
}
