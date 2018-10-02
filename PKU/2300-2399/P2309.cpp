#include<iostream>
using namespace std;

int main()
{
    int t,n,nn,a[32],i,p=1,cnt;
    for(i=0;i<32;i++)
    {
        a[i]=p;
        p*=2;                 
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        nn=n;
        cnt=0;
        while(!(n&1))
        {
            n/=2;
            cnt++;          
        }
        cout<<nn-a[cnt]+1<<' '<<nn+a[cnt]-1<<endl; 
    }    
    
    return 0;
}
