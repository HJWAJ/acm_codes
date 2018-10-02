#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int t,tt,n,a[10005],i,j,k,tmp,cnt,ans[10005];
    bool val;
    scanf("%d",&t);
    while(t--)    
    {
        scanf("%d%d",&tt,&n);
        printf("%d %d\n",tt,n/2+1);
        cnt=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&tmp);
            j=0;
            val=0;
            while(j<i)
            {
                if(tmp<a[j])
                {
                    val=1;
                    for(k=i-1;k>=j;k--)a[k+1]=a[k];
                    a[j]=tmp;
                    break;
                } 
                j++;
            }
            if(val==0)a[i]=tmp;
            if(!(i&1))ans[i/2]=a[i/2];
        }
        for(i=0;i<n/2;i++)
        {
            if(i%10==9)printf("%d\n",ans[i]); 
            else printf("%d ",ans[i]);                  
        }
        printf("%d\n",ans[i]);
    }
    
    return 0;
}
