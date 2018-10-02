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

bool isPrime(int n)
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
    int n,nn,flag,p,val;
    while(scanf("%d",&n) && n!=0)
    {
        if(n==1)
        {
            printf("0\n");
            continue;        
        }
        if(isPrime(n))
        {
            printf("%d\n",n-1);
            continue;
        }
        nn=int(sqrt(double(n)));
        p=n;
        val=flag=0;
        while(n!=1)
        {
            if(n%sushu[flag]==0)
            {
                if(val==0)
                {
                    val=1;
                    p/=sushu[flag];
                    p*=(sushu[flag]-1);
                }
                n/=sushu[flag];
                continue;
            }
            else 
            {
                val=0;
                flag++;
            }
            if(sushu[flag]>nn)
            {
                p/=n;
                p*=(n-1);
                break;                  
            }
        }             
        printf("%d\n",p);
    }    
    
    return 0;
}
