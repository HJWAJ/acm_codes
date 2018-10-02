#include<iostream>
using namespace std;

int main()
{
    int n,i,count=0;
    cin>>n;
    for(i=1;i<n;i++)
    {
        if(n-i*(i+1)/2<0)break;
        if((n-i*(i+1)/2)%i==0)count++;
    }
    cout<<count;
    
    system("pause");
    return 0;
}
