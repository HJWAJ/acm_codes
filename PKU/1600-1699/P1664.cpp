#include<iostream>
#include<cstring>
using namespace std;

//int a[100][100];

int f(int m,int n)
{
    if(m<0 || n<0)return 0;
    if(m==0 || n==0)return 1;
    if(m==1 || n==1)return 1;
    //if(a[m-1][n-1]!=0)return a[m-1][n-1];
    return f(m-n,n)+f(m,n-1);    
}

int main()
{
    int m,n,t;
    //memset(a,0,sizeof(a));
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        //if(a[m-1][n-1]!=0)cout<<a[m-1][n-1];
        cout<<f(m,n)<<endl;
    }
    
    system("pause");
    return 0;
}
