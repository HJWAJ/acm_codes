#include<iostream>
using namespace std;

int main()
{
    int s,n;
    cin>>s;
    n=1;
    while(s>n*(n+1)/2)
    {
        n++;                  
    }    
    if(s%2==0)
    {if(n%4==1)cout<<n+2;
    else if(n%4==2)cout<<n+1;
    else cout<<n;}
    
    else
    {
    if(n%4==3)cout<<n+2;
    else if(n%4==0)cout<<n+1;
    else cout<<n;
    }
    
    system("pause");
    return 0;
}
