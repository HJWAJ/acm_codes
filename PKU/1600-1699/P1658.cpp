#include<iostream>
using namespace std;

int main()
{
    int t,a[10000][5];
    cin>>t;
    for(int i=0;i<t;i++)
       for(int j=0;j<4;j++)
          cin>>a[i][j];
          
    
    for(int i=0;i<t;i++)
          {if(a[i][1]-a[i][0]==a[i][2]-a[i][1] && a[i][2]-a[i][1]==a[i][3]-a[i][2])
             {for(int j=0;j<4;j++)cout<<a[i][j]<<" ";    cout<<a[i][3]+a[i][1]-a[i][0]<<endl;}
          else
             {for(int j=0;j<4;j++)cout<<a[i][j]<<" ";    cout<<a[i][3]*a[i][1]/a[i][0]<<endl;}
             }
    system("pause");
    return 0;
}
