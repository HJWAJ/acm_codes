#include<iostream>
using namespace std;

int main()
{
    int t,i;
    long long int w,a;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>a;
        w=(a*a*(a+1)*(a+1)/4+a*(a+1)*(2*a+1)/2+a*(a+1))/2;
        cout<<i<<' '<<a<<' '<<w<<endl;                 
    }
    
    system("pause");
    return 0;
}
