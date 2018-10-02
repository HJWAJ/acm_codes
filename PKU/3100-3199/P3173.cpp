#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n,s,a[20][20],i,j;
    cin>>n>>s;
    memset(a,0,sizeof(a));
    for(i=0;i<n;i++)
        for(j=0;j<=i;j++) 
        {   
            a[j][i]=s++;
            if(s>9)s-=9;
        }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==0)cout<<"  ";
            else cout<<a[i][j]<<' ';                
        }   
        cout<<endl;
    }
    
    system("pause");
    return 0;
}
