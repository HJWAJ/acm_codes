#include<iostream>
using namespace std;

int main()
{
    int t,a,b,ra,rb,sum,rsum;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        ra=0;
        rb=0;
        rsum=0;
        while(a>0)
        {
            ra=ra*10+a%10;
            a/=10;          
        }         
        while(b>0)
        {
            rb=rb*10+b%10;
            b/=10;          
        } 
        sum=ra+rb;
        while(sum>0)
        {
            rsum=rsum*10+sum%10;
            sum/=10;            
        }
        cout<<rsum<<endl;
    }
    
    system("pause");
    return 0;
}
