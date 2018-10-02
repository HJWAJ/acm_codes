#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int a[100],b[100],n,r,p,c,i,j;
    while(cin>>n>>r && (n||r))
    {
        for(i=1;i<=n;i++)a[i]=n+1-i;
        for(i=0;i<r;i++)
        {
            cin>>p>>c;
            for(j=1;j<=c;j++)b[j]=a[p+j-1];
            for(j=1;j<p;j++)b[c+j]=a[j];
            for(j=p+c;j<=n;j++)b[j]=a[j];
            memcpy(a,b,400);
        }
        cout<<a[1]<<endl;
    }    
    
    return 0;
}
