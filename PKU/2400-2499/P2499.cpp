#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int t,a,b,l,r,tt=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        l=r=0;
        tt++;
        while(!(a==1 || b==1))
        {
            if(a>b)
            {
                l+=(a/b);
                a%=b;       
            }        
            else
            {
                r+=(b/a);
                b%=a;    
            }     
        } 
        if(a==1)r+=(b-1);
        if(b==1)l+=(a-1);
        printf("Scenario #%d:\n%d %d\n\n",tt,l,r);
    }    
    
    return 0;
}
