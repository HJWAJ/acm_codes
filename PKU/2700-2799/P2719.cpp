#include<iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n && n!=0)
    {
        int m=n;
        int a[10],i=0;
        int sum=0;
        while(n/10!=0)
        {
            a[i]=n%10;
            n/=10;
            i++;              
        }       
        a[i]=n;
        for(int j=i;j>=0;j--)
        {
            if(a[j]<4)sum=sum*9+a[j]; 
            else sum=sum*9+a[j]-1;       
        }     
        cout<<m<<": "<<sum<<endl; 
    }    
    
    system("pause");
    return 0;
}
