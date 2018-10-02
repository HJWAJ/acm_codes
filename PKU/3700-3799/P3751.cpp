#include<iostream>
using namespace std;

int main()
{
    int n;
    char a[20];
    
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a[11]=='0' && a[12]=='0')
        {cout<<a[5]<<a[6]<<a[7]<<a[8]<<a[9]<<a[7]<<a[0]<<a[1]<<a[2]<<a[3]<<a[10]<<char(a[11]+1)<<char(a[12]+2);
        for(int j=0;j<6;j++)cout<<a[13+j];
        cout<<"am"<<endl;
        }    
        else if((a[11]=='0' && a[12]!='0') || (a[11]=='1' && a[12]<'2'))  
        {
         cout<<a[5]<<a[6]<<a[7]<<a[8]<<a[9]<<a[7]<<a[0]<<a[1]<<a[2]<<a[3]<<a[10]<<a[11]<<a[12];
        for(int j=0;j<6;j++)cout<<a[13+j];
        cout<<"am"<<endl;    
        } 
        else if(a[11]=='1' && a[12]=='2')
        {
        cout<<a[5]<<a[6]<<a[7]<<a[8]<<a[9]<<a[7]<<a[0]<<a[1]<<a[2]<<a[3]<<a[10]<<a[11]<<a[12];
        for(int j=0;j<6;j++)cout<<a[13+j];
        cout<<"pm"<<endl;    
        } 
        else
        {cout<<a[5]<<a[6]<<a[7]<<a[8]<<a[9]<<a[7]<<a[0]<<a[1]<<a[2]<<a[3]<<a[10]<<char(a[11]-1)<<char(a[12]-2);
        for(int j=0;j<6;j++)cout<<a[13+j];
        cout<<"pm"<<endl;    
        }
    }
    
        
    
    
    system("pause");
    return 0;
}
