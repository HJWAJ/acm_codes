#include<iostream>
using namespace std;

int main()
{
    int m,n,a[10],b[10],s=0;
    cin>>m>>n;
    for(int i=0;i<10;i++)
    {
        a[i]=m%10;
        b[i]=n%10;
        m/=10;
        n/=10;        
    }
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
           s=s+a[i]*b[j];
           
    cout<<s;
    
    system("pause");
    return 0;    
}
