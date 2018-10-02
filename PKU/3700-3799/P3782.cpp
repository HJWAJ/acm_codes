#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
    int t,tt,n,a[10005],sum,i,j,sq,cnt[10000],flag;
    scanf("%d",&t);
    while(t--)    
    {
        scanf("%d%d",&tt,&n);
        sum=flag=0;
        memset(cnt,0,sizeof(cnt));
        for(i=0;i<n;i++)
        {
            scanf("%d",a+i);
            sum+=a[i];
        }
        sq=int(sqrt(double(sum)));
        for(i=1;i<sq;i++)
        {
            if(sum%i==0)
            {
                cnt[flag++]=i;
                cnt[flag++]=sum/i;       
            }
        }
        if(sum%sq==0)
        {
            if(sum/sq==sq)cnt[flag++]=sq;
            else 
            {
                cnt[flag++]=sq;
                cnt[flag++]=sum/sq;     
            }             
        }
        sort(cnt,cnt+flag);
        for(i=0;i<flag;i++)
        {
            sum=0;
            for(j=0;j<n;j++)
            {
                sum+=a[j];
                if(sum==cnt[i])sum=0;
                if(sum>cnt[i])break;              
            }
            if(j==n)
            {
                printf("%d %d\n",tt,cnt[i]);
                break;        
            }
        }
    }
    
    //system("pause");
    return 0;
}
