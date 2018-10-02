#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
    int n,i,a[3005];
    bool sub[3005];
    while(scanf("%d",&n)!=EOF)
    {
        memset(sub,0,sizeof(sub));
        for(i=0;i<n;i++)scanf("%d",a+i);
        for(i=0;i<n-1;i++)
        {
            if(abs(a[i+1]-a[i])>=n)
            {
                printf("Not jolly\n");
                goto label;                       
            }
            if(sub[abs(a[i+1]-a[i])])
            {
                printf("Not jolly\n");
                goto label;                       
            }
            sub[abs(a[i+1]-a[i])]=1;
        }
        printf("Jolly\n");
        label:;
    }    
    
    return 0;
}
