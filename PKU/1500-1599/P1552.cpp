#include<iostream>
using namespace std;

int main()
{
    int a[100],n,k;
    cin>>a[0];
    while(a[0]!=-1)
    {
        for(int i=1;i<100;i++)a[i]=0;
        n=1;
        cin>>a[n];
        while(a[n]!=0)
        {
            n++;
            cin>>a[n];              
        }
        
        
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(a[i]==2*a[j])k++;
        cout<<k<<endl;
        k=0;
        cin>>a[0];              
    }
    
    system("pause");
    return 0;    
}
