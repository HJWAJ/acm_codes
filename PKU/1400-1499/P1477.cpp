#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n,i,a[50],sum,tt=0,cnt;
    while(scanf("%d",&n) && n!=0)
    {
        tt++;
        printf("Set #%d\n",tt);
        sum=cnt=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",a+i);
            sum+=a[i];                  
        }
        sum/=n;
        for(i=0;i<n;i++)
        {
            if(a[i]>sum)cnt+=(a[i]-sum);    
        }
        printf("The minimum number of moves is %d.\n\n",cnt);
    }    
    
    return 0;
}
