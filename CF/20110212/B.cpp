#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int n,a[105],i,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
        sum+=a[i];
    }
    if(sum&1)printf("%d\n",sum);
    else
    {
        sort(a,a+n);
        for(i=0;i<n;i++)
            if(a[i]&1)
            {
                sum-=a[i];
                break;
            }
        if(i==n)printf("0\n");
        else printf("%d\n",sum);    
    }
    
    return 0;
}
