#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int m,sum,i,j,val[100005],a[100005];
    while(scanf("%d",&m)!=EOF)
    {
        memset(val,0,sizeof(val));
        sum=0;
        for(i=1;i<=m;i++)scanf("%d",a+i);
        for(i=1;i<=m;i++)
        {
            if(a[i]%m==0)
            {
                printf("1\n%d\n",a[i]);
                break;
            }
            sum+=a[i];
            sum%=m;
            if(sum==0)
            {
                printf("%d\n",i);
                for(j=1;j<=i;j++)printf("%d\n",a[j]);
                break;   
            }
            if(val[sum]==0)val[sum]=i;
            else
            {
                printf("%d\n",i-val[sum]);
                for(j=val[sum]+1;j<=i;j++)printf("%d\n",a[j]);
                break;    
            }
        }
    }
    
    return 0;    
}
