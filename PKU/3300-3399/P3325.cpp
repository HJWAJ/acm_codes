#include<iostream>
using namespace std;

int main()
{
    int n,a[100],i,max,min,s,avr;
    while(cin>>n && n!=0)
    {
        max=-1;
        min=2000;
        s=0;
        for(i=0;i<n;i++)cin>>a[i];
        for(i=0;i<n;i++)
        {
            s+=a[i];
            if(max<a[i])max=a[i];
            if(min>a[i])min=a[i];
        }             
        s=s-min-max;
        avr=s/(n-2);
        cout<<avr<<endl;
    }    
    
    system("pause");
    return 0;
}
