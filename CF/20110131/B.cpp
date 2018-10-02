#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int sushu[50000];
bool dabiao[200001];

void sushubiao()
{
    memset(sushu,0,sizeof(sushu));
    memset(dabiao,0,sizeof(dabiao));
    dabiao[0]=1;
    dabiao[1]=1;
    int num;
    int i,j;  
    for(i=2;i<=50000;i++)
        for(j=2;j<=50000/i;j++)
            dabiao[j*i]=1;  
    
    j=0;
    for(i=2;i<=50000;i++)if(dabiao[i]==0){sushu[j]=i;j++;}
} 

bool isPrime(__int64 n)
{
    int i;
    //*/
    if(n<=50000)
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
    int n,flag=0;
    scanf("%d",&n);
    printf("%d",n);
    if(n==1)
    {
        printf("\n");
        return 0;        
    }
    while(n)
    {
        while(n%sushu[flag]==0)
        {
            n/=sushu[flag];
            printf(" %d",n);
            if(n==1)return 0;                       
        }
        flag++;
        if(isPrime(n))
        {
            printf(" 1\n");
            break;              
        }
    }
        
    return 0;
}
