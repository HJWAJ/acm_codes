#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int n;
    char a[201];
    
    cin>>n;
    while(n!=0)
    {
        cin>>a;
        int i=strlen(a);
        
        if((i/n)%2==0)
        for(int k=0;k<n;k++)
            for(int j=0;j<i;j=j+n*2)
                cout<<a[j+k]<<a[j+2*n-k-1];
        else
        for(int k=0;k<n;k++)
            {for(int j=0;j<i-n;j=j+n*2)
                cout<<a[j+k]<<a[j+2*n-k-1];
             cout<<a[i-n+k];    
            }
            
        cout<<endl;
        
        cin>>n;
        
        
               
    }    
    
    system("pause");
    return 0;
}
