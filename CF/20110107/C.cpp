#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int n,a[20000];
    int flag1,flag2,i;
    bool used[10001];
    while(scanf("%d",&n)!=EOF)
    {
        if(n==1){printf("1\n");continue;}
        flag1=9999;flag2=10000;
        memset(used,0,sizeof(used));
        memset(a,0,sizeof(a));
        a[flag1]=1;a[flag2]=n;
        used[1]=used[n]=1;
        for(i=n-1;i>=1;i--)
        {
            if(a[flag1]+i<n && used[a[flag1]+i]==0)
            {
                used[a[flag1]+i]=1;
                a[flag1-1]=a[flag1--]+i;
                continue;                
            }
            else if(a[flag1]-i>0 && used[a[flag1]-i]==0)
            {
                used[a[flag1]-i]=1;
                a[flag1-1]=a[flag1--]-i;
                continue;                
            }
            else if(a[flag2]-i>0 && used[a[flag2]-i]==0)
            {
                used[a[flag2]-i]=1;
                a[flag2+1]=a[flag2++]-i;
                continue;                
            }
            else if(a[flag2]+i<n && used[a[flag2]+i]==0)
            {
                used[a[flag2]+i]=1;
                a[flag2+1]=a[flag2++]+i;
                continue;                
            }
        }
        i=0;
        while(a[i]==0)i++;
        while(a[i]!=0)printf("%d ",a[i++]);
        printf("\n");                          
    }    
    
    return 0;
}
