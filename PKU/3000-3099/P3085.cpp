#include<iostream>
using namespace std;

int main()
{
    int t,m,q,d,n,p,i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>m;
        q=m/25;
        m%=25;
        d=m/10;
        m%=10;
        n=m/5;
        p=m%5;
        cout<<i<<' '<<q<<" QUARTER(S), "<<d<<" DIME(S), "<<n<<" NICKEL(S), "<<p<<" PENNY(S)"<<endl;          
    }    
    
    system("pause");
    return 0;
}
