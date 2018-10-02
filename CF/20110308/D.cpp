#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int sushu[50000],a[1000];
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

void multi(int a[],int n)
{
    int i;
    for(i=0;i<1000;i++)a[i]*=n;
    for(i=0;i<1000;i++)
    {
        a[i+1]+=(a[i]/10);
        a[i]%=10;                   
    }
}

void Print(int a[])
{
    int i,len;
    for(i=999;i>=0;i--)if(a[i])break;
    len=i;
    for(i=len;i>=0;i--)printf("%d",a[i]);
    printf("\n");     
}

int main()
{
    sushubiao();
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==2){printf("-1\n");return 0;}
        for(i=0;i<n;i++)
        {
            memset(a,0,sizeof(a));
            a[0]=1;
            for(j=0;j<n;j++)
            {
                if(i!=j)multi(a,sushu[j]);             
            }
            Print(a);
        }                        
    }    
    //system("pause");
    return 0;
}
