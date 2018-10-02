#include<iostream>
#include<cstring>
using namespace std;

int a[100][100],h[100][100],m,n;

int dp(int i,int j)
{
    int max=0;
    if(h[i][j]!=0)return h[i][j];
    if(j>=1)
        if(a[i][j]>a[i][j-1] && max<dp(i,j-1))max=dp(i,j-1);       
    if(j<=n-2)
        if(a[i][j]>a[i][j+1] && max<dp(i,j+1))max=dp(i,j+1);
    if(i>=1)
        if(a[i][j]>a[i-1][j] && max<dp(i-1,j))max=dp(i-1,j);
    if(i<=m-2)
        if(a[i][j]>a[i+1][j] && max<dp(i+1,j))max=dp(i+1,j);
    return h[i][j]=max+1;    
}

int main()
{
    int i,j,max=0;
    memset(h,0,sizeof(h));
    memset(a,0,sizeof(a));
    cin>>m>>n;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
           cin>>a[i][j];
           
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {    
            dp(i,j);
            if(h[i][j]>max)max=h[i][j];
            //cout<<h[i][j]<<' ';
        }
    cout<<max<<endl;
    
    system("pause");
    return 0;
}
