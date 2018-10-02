#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

bool check(int n)
{
    int nn=n,cnt=0;
    while(nn){nn/=10;cnt++;}
    if(cnt!=4)return 1;
    if(n%10==n/10%10 && n/10%10==n/100%10 && n/100%10==n/1000)return 1;
    return 0;     
}

int maxi(int n)
{
    int a[4],res=0,i,cnt=0;
    while(n)
    {
        a[cnt++]=n%10;
        n/=10;        
    }
    sort(a,a+cnt);
    for(i=cnt-1;i>=0;i--)
    {
        res*=10;
        res+=a[i];                
    }
    return res;
}

int mini(int n)
{
    int a[4],res=0,i,cnt=0;
    while(n)
    {
        a[cnt++]=n%10;
        n/=10;        
    }
    sort(a,a+cnt);
    for(i=0;i<cnt;i++)
    {
        res*=10;
        res+=a[i];                
    }
    return res;
}

int main()
{
    int n,min,max,cnt;
    while(scanf("%d",&n) && n!=-1)
    {
        printf("N=%d:\n",n);
        if(check(n))printf("No!!\n");
        else
        {
            cnt=0;
            while(n!=6174 && n!=0)
            {
                max=maxi(n);
                min=mini(n);
                n=max-min;
                printf("%d-%d=%d\n",max,min,n);
                cnt++;            
            }    
            printf("Ok!! %d times\n",cnt);
        }            
    }
    
    return 0;
}
