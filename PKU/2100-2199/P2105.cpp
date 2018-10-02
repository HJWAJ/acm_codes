#include<iostream>
using namespace std;

int main()
{
    int n,s;
    char a[33];
    cin>>n;
    for(int i=0;i<n;i++)
    {   
        cin>>a;
        for(int j=0;j<4;j++)
        {    
             int p=1,s=0;
             for(int k=0;k<8;k++)
                    {s+=(a[8*j+7-k]-'0')*p;
                    p*=2;}    
             if(j!=3)cout<<s<<'.';
             if(j==3)cout<<s;
        }
        cout<<endl;    
    }
    system("pause");
    return 0;
}
