#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int val[1000001]; 

int main()
{
    long long int t,d,n,a[50005],i,tmp,flag,cnt[50005],sum;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&d,&n);
        sum=a[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&tmp);
            a[i]=(a[i-1]+tmp)%d;
        }
        memset(val,-1,sizeof(val));
        memset(cnt,0,sizeof(cnt));
        flag=0;
        for(i=0;i<=n;i++)
        {
            if(val[a[i]]==-1)
            {
                val[a[i]]=flag;
                cnt[flag]=1;
                flag++;
            }
            else cnt[val[a[i]]]++;
        }
        for(i=0;i<flag;i++)
        {
            if(cnt[i]<2)continue;
            else sum+=(cnt[i]*(cnt[i]-1)/2);
        }
        printf("%lld\n",sum);
    }
    
    return 0;
}
