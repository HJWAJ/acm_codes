#include<iostream>
using namespace std;

int main()
{
    int t,i;
    //double pow7[4]={2401,343,49,7};
    cin>>t;
    for(i=1;i<=t;i++)
    {
        int n,d,b,e,j;  
        cin>>n>>d>>b>>e;
        int mod=n%d;
        int decimal[250];
        for(j=0;j<250;j++)
        {
            decimal[j]=mod*7/d;
            mod=mod*7%d;
        }
        cout<<"Problem set "<<i<<": "<<n<<" / "<<d<<", base 7 digits "<<b<<" through "<<e<<": ";
        for(j=b;j<=e;j++)cout<<decimal[j];
        cout<<endl;      
    }
    
    system("pause");
    return 0;
}
