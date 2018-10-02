#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int t,tt=0,a[3],i;
    scanf("%d",&t);
    while(t--)
    {
        tt++;
        for(i=0;i<3;i++)scanf("%d",a+i);
        sort(a,a+3);
        printf("Scenario #%d:\n",tt);
        if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2])printf("yes\n\n");
        else printf("no\n\n");          
    }    
    
    return 0;
}
