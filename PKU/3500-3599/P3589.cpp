#include<iostream>
using namespace std;

int main()
{
    short int n,p,q; 
    char a[1000][4],b[1000][4];
    cin>>n;
    for(int i=0;i<n;i++)
      { for(int j=0;j<4;j++)
          cin>>a[i][j];
       for(int j=0;j<4;j++)
          cin>>b[i][j];}
    
    for(int i=0;i<n;i++)
    {   p=0;q=0;
       
       for(int j=0;j<4;j++)
       {if(a[i][j]==b[i][j])p++;}
       
       for(int j=0;j<4;j++)
          for(int k=0;k<4;k++)
       {if(a[i][j]==b[i][k])q++;}
       
       cout<<p<<"A"<<q-p<<"B"<<endl;
    
    }  
    
    system("pause");
    return 0;
}
