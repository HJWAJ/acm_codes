#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int m,n,sum,i,j,val[100005],a;
    while(scanf("%d%d",&m,&n) && (m||n))
    {
        memset(val,0,sizeof(val));
        sum=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);
            sum+=a;
            sum%=m;
            if(a==0)continue;
            if(a%m==0)
            {
                printf("%d\n",i);
                break;
            }
            else
            {
                if(sum==0)
                {
                    for(j=1;j<=i;j++)printf("%d ",j);
                    printf("\n");
                    break;          
                }
                if(val[sum]==0)val[sum]=i;
                else
                {
                    for(j=val[sum]+1;j<=i;j++)printf("%d ",j);
                    printf("\n");
                    break;    
                }
            }
        }
        if(i>n)printf("no sweets\n");
        i++;
        for(;i<=n;i++)scanf("%d",&a);      
    }
    
    return 0;    
}
