#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n,i,a[100];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<=n;i++)scanf("%d",&a[i]);
        if(n<2)printf("YES\n");
        if(n==2)
        {
            if(a[1]*a[1]>=4*a[0]*a[2])printf("NO\n");
            else printf("YES\n");        
        }
        else printf("NO\n");    
    }
    
    return 0;
}
