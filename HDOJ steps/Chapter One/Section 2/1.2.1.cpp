#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n,a,b,sum;
    while(scanf("%d",&n) && n)
    {
        sum=n*5;
        b=0;
        while(n--)
        {
            scanf("%d",&a);
            if(a>b)sum+=(a-b)*6;
            else sum+=(b-a)*4;
            b=a;          
        }       
        printf("%d\n",sum); 
    }    
    
    return 0;
}
