#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int n,a[1000],i,b[1000],cnt;
    while(cin>>n && n!=0)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        cnt=1;
        cin>>a[0];
        b[0]=a[0];
        for(i=1;i<n;i++)
        {
            cin>>a[i];
            if(a[i]!=a[i-1])
            {
                b[cnt]=a[i];
                cnt++;                
            }  
        }      
        for(i=0;i<cnt;i++)cout<<b[i]<<' ';
        cout<<'$'<<endl;    
    }
    
    
    system("pause");
    return 0;
}
