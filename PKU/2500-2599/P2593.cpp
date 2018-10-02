#include<iostream>
using namespace std;

int main()
{
    int n,a[100005],max1[100005],max2[100005],maxa,maxb,max,sum,i;
    while(scanf("%d",&n) && n!=0)
    {
        sum=0;
        maxa=maxb=-999999;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
            if(sum<0)sum=0;
            if(maxa<sum){maxa=sum;max1[i]=sum;}
            else max1[i]=maxa;
            //printf("%d ",max1[i]);
        }
        //printf("\n");
        sum=0;
        for(i=n-1;i>=0;i--)
        {
            sum+=a[i];
            if(sum<0)sum=0;
            if(maxb<sum){maxb=sum;max2[i]=sum;}
            else max2[i]=maxb;
            //printf("%d ",max1[i]);                   
        }
        //printf("\n");
        max=-999999;
        for(i=0;i<n-1;i++)if(max<max1[i]+max2[i+1])max=max1[i]+max2[i+1];
        int cnt=0;
        for(i=0;i<n;i++)
        {
            if(a[i]>=0)cnt++;
            if(cnt==2)break;
        }
        if(i==n)
        {
            for(i=0;i<n-1;i++)if(a[n-1]<a[i])swap(a[n-1],a[i]);
            for(i=0;i<n-2;i++)if(a[n-2]<a[i])swap(a[n-2],a[i]);
            max=a[n-1]+a[n-2];        
        }
        printf("%d\n",max);
    }    
    
    system("pause");
    return 0;
}
