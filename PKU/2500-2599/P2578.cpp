#include<iostream>
using namespace std;

int main()
{
    int a,b,c,h=168;
    cin>>a>>b>>c;
    if(a<h)cout<<"CRASH "<<a<<endl;
    else if(b<h)cout<<"CRASH "<<b<<endl;
    else if(c<h)cout<<"CRASH "<<c<<endl;
    else cout<<"NO CRASH"<<endl;    
    
    system("pause");
    return 0;
}
