#include<iostream>
using namespace std;

int main()
{
    int m,n,a[100],sum=0,i,j,b[100];
    cin>>n>>m;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<n;i++)b[i]=1;
    
    if(m==2)
    {
        for(i=0;i<n;i++)
        sum=sum+a[i]*a[i];        
    }
    else 
    {
        for(i=0;i<n;i++)
        {
            if(a[i]>0)
            {
                for(j=0;j<m;j++)b[i]=b[i]*a[i]; 
                sum=sum+b[i];
            }               
        }     
    }
    cout<<sum<<endl;
    
    system("pause");
    return 0;
}
