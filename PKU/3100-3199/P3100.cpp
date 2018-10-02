#include<iostream>
#include<cstring>
using namespace std;

int multiple(int n,int num)
{
    long long int i,p=1;
    for(i=0;i<n;i++)
        p*=num;
    return p;
}

int main()
{
    long long int b,n,a1=0,a2,i,j;
    while(cin>>b>>n && b!=0 || n!=0)
    {
         for(i=1;;i++)
         {
             a2=multiple(n,i);
             if(a2>b)break;
             a1=a2;
         }
         if(a2-b>b-a1)cout<<i-1<<endl;
         else cout<<i<<endl;               
    }    
    
    system("pause");
    return 0;
}
