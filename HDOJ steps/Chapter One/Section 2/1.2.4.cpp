#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n,t=0,a[105],i,sum,res;
    while(scanf("%d",&n) && n)
    {
        t++;
        res=sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",a+i);
            sum+=a[i];                
        }
        sum/=n;
        for(i=0;i<n;i++)
            if(a[i]>sum)res+=(a[i]-sum);
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",t,res);                     
    }
    
    return 0;
}
