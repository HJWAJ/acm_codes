#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int sushu[50000];
bool dabiao[200001];
__int64 sushu2[200000];
__int64 dis[200000]; 
bool dabiao2[1000001];

void sushubiao()
{
    memset(sushu,0,sizeof(sushu));
    memset(dabiao,0,sizeof(dabiao));
    dabiao[0]=1;
    dabiao[1]=1;
    int num;
    int i,j;  
    for(i=2;i<=200000;i++)
        for(j=2;j<=200000/i;j++)
            dabiao[j*i]=1;  
    
    j=0;
    for(i=2;i<=50000;i++)if(dabiao[i]==0){sushu[j]=i;j++;}
} 

bool isPrime(__int64 n)
{
    int i;
    //*/
    if(n<=200000)
    {
        if(dabiao[n]==0)return 1;
        else return 0;             
    }
    //*/
    for(i=0;sushu[i]<=int(sqrt(double(n)));i++)
    {
        if(n%sushu[i]==0)return 0;                                   
    }  
    return 1;   
}

int main()
{
    sushubiao();
    __int64 l,u,i,j;
    while(scanf("%lld%lld",&l,&u)!=EOF)
    {
        memset(sushu2,0,sizeof(sushu2));
        memset(dis,0,sizeof(dis));
        memset(dabiao2,0,sizeof(dabiao2));
        //*/用素数表筛选素数 
        for(i=2;i*i<=u;i++)
        {
            __int64 j=l/i*i;
            if(j<i*i)j=i*i;
            if(j<l)j+=i;
            for(;j<=u;j+=i)
            dabiao2[j-l]=1;
        }
        j=0;
        for(i=l;i<=u;i++)
            if(dabiao2[i-l]==0 && i!=1)
            {
                sushu2[j]=i;
                j++;                   
            }
        //*/ 
        if(j==1){printf("There are no adjacent primes.\n");continue;}
        for(i=0;i<j-1;i++)
        {
            dis[i]=sushu2[i+1]-sushu2[i];                  
        }
        int max=dis[0],min=dis[0],flag1=0,flag2=0;
        for(i=1;i<j-1;i++)
        {
            if(max<dis[i]){max=dis[i],flag1=i;}
            if(min>dis[i]){min=dis[i],flag2=i;}
        }
        printf("%lld,%lld are closest, %lld,%lld are most distant.\n",sushu2[flag2],sushu2[flag2+1],sushu2[flag1],sushu2[flag1+1]);
    }
        
    return 0;
}
