#include<iostream>
using namespace std;

int main()
{
    int a[11],b[11],i,x,y;
    a[0]=3;b[0]=1;
    for(i=1;i<11;i++)
    {
        a[i]=a[i-1]*a[0]+8*b[i-1]*b[0];
        b[i]=a[i-1]*b[0]+b[i-1]*a[0];
        x=b[i];
        y=(a[i]-1)/2;
        printf("%10d%10d\n",x,y);                 
    }    
    
    system("pause");
    return 0;
}
