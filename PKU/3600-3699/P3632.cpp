#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int m,n,a[101],min=999999,max=0;
    cin>>m;
    for(int i=0;i<m;i++)
    {  cin>>n;
       for(int j=0;j<101;j++)a[j]=0;
       for(int j=0;j<n;j++)
          cin>>a[j];
          
    for(int j=0;j<n;j++)
    {if(max<a[j])max=a[j];
     if(min>a[j])min=a[j];}
    cout<<2*(max-min)<<endl;
    max=0;min=999999;}
    
    system("pause");
    return 0;    
}
