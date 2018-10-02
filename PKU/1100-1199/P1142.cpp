#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int sushu[50000];
bool dabiao[200001];
int sumdabiao[200001];

int add(int n)
{
    int sum=0;
    while(n)
    {
        sum+=(n%10);
        n/=10;
    }
    return sum;
}

void sushubiao()
{
    memset(sushu,0,sizeof(sushu));
    memset(dabiao,0,sizeof(dabiao));
    memset(sumdabiao,0,sizeof(sumdabiao));
    dabiao[0]=1;
    dabiao[1]=1;
    int i,j;  
    for(i=2;i<=100000;i++)
        for(j=2;j<=100000/i;j++)
            dabiao[j*i]=1;  
    j=0;
    for(i=2;i<=100000;i++)
        if(dabiao[i]==0)
        {
            sushu[j]=i;
            sumdabiao[i]=add(i);
            j++;
        }
}

bool isprime(int n)
{
    int i,m=int(sqrt(double(n)));
    for(i=2;i<=m;i++)
        if(n%i==0)return 0;
    return 1;     
}

bool issmith(int n)
{
    if(isprime(n))return 1;
    int a[10000];
    int nlength=0,i=0,nn=n;
    while(n>1)
    {
        if(n%sushu[i]==0)
        {
            n/=sushu[i];
            a[nlength++]=sushu[i];
        }
        else
        {
            i++;
            if(sushu[i]==0){a[nlength++]=n;break;}    
        } 
    }
    int sum1=add(nn);
    int sum2=0;
    for(i=0;i<nlength-1;i++)
    {
        sum2+=sumdabiao[a[i]];                      
    }
    sum2+=add(a[nlength-1]);
    if(sum1==sum2)return 0;
    else return 1;
}

int main()
{
    sushubiao();
    int n;
    while(scanf("%d",&n) && n!=0)
    {
        n++;
        while(issmith(n))n++;
        printf("%d\n",n);                     
    }
    
    return 0;
}
