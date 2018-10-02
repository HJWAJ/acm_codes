#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,k,s,t,r,m,sum;
    cin>>n>>k;
    m=n;
    while(k--)
    {
        n=m;
        cin>>s>>t>>r;
        if(n%(s*t)!=0)sum=n/(s*t)*(t+r);
        else sum=n/(s*t)*(t+r)-r;
        n=n%(s*t);
        if(n%s==0)sum=sum+n/s;
        else sum=sum+n/s+1;
        cout<<sum<<endl;
    }
        
    system("pause");
    return 0;
}
