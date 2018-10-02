#include<iostream>
using namespace std;

int main()
{
    int a[200],i;
    a[0]=1;a[1]=2;a[2]=4;a[3]=6;a[4]=9;
    for(i=5;i<200;i++)
        a[i]=(a[i-4]+a[i-3]+a[i-1])%2005;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        n%=200;
        printf("%d\n",a[n]);                          
    }    
    
    system("pause");
    return 0;
}
