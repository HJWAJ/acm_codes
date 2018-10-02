#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    int t,y1,y2,x,y;
    char x1,x2;
    cin>>t;
    while(t--)
    {
        cin>>x1>>y1>>x2>>y2;
        if(x1==x2 && y1==y2){cout<<"0 0 0 0"<<endl;continue;}
        x=abs(x1-x2);
        y=abs(y1-y2);
        cout<<(x>y?x:y)<<' ';
        if(x==0 || y==0 || x==y)cout<<"1 ";
        else cout<<"2 ";
        if(x==0 || y==0)cout<<"1 ";
        else cout<<"2 ";
        if(x==y)cout<<1<<endl;
        else if(!((x+y)&1))cout<<2<<endl;
        else cout<<"Inf"<<endl;   
    }    
    
    return 0;
}
