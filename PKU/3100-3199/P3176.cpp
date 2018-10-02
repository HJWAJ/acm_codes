#include<iostream>
using namespace std;

int main()
{
    int n,a[1001][1001];
    cin>>n;
    for(int i=0;i<n;i++)
       for(int j=0;j<i+1;j++)
          cin>>a[i][j];
          
    for(int i=n-2;i>=0;i--)
        for(int j=0;j<=i;j++)
        {if(a[i+1][j]>a[i+1][j+1])a[i][j]+=a[i+1][j];
         else a[i][j]+=a[i+1][j+1];}
    
    cout<<a[0][0]<<endl;    
    
    
    system("pause");
    return 0;
}
