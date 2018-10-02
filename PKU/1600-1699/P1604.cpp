#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int p=1,i;
        for(i=1;i<=n;i++)
        {
            p*=i;
            if(i%5==0)p/=10;
            if(i%25==0)p/=10;
            if(i%125==0)p/=10;
            if(i%625==0)p/=10;
            if(i%3125==0)p/=10;
            if(i%15625==0)p/=10;
            p%=100000;                
        }
        p%=10;
        cout<<setw(5)<<n<<" -> "<<p<<endl;             
    }    
    
    system("pause");
    return 0;
}
