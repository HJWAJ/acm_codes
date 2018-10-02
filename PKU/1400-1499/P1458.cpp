#include <iostream>
#include <cstring>
using namespace std;

int max(int a,int b)
{
    if(a>b)return a;
    else return b;
}
 
int main()
{
    int la,lb,f[500][500];
    char a[500],b[500];
    while(cin>>a>>b)
    {
        la=strlen(a);
        lb=strlen(b);
        for(int i=1;i<=la;i++)
            for(int j=1;j<=lb;j++)
                f[i][j]=0;
        for(int i=1;i<=la;i++)
            for(int j=1;j<=lb;j++)
            {    
                if(a[i-1]==b[j-1])f[i][j]=f[i-1][j-1]+1;
                else f[i][j]=max(f[i-1][j],f[i][j-1]);
            }
        cout<<f[la][lb]<<endl;
    }
    
    system("pause");
    return 0;    
}

