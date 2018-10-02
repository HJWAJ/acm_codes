#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int t,tt=0,n,a[1005],i,j,cnt;
    scanf("%d",&t);
    while(t--)
    {
        tt++;
        cnt=0;
        printf("Scenario #%d:\n",tt);
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d",a+i);
        for(i=0;i<n-1;i++)
            for(j=0;j<n-1-i;j++)                
                if(a[j]>a[j+1])
                {
                    swap(a[j],a[j+1]);
                    cnt++;               
                }
        printf("%d\n\n",cnt);
    }    
    
    return 0;
}
