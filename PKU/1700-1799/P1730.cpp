#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int sushu[100000];
bool dabiao[1000001];
int dabiao1[100000];

int gcd(int a,int b)
{
    if(a<b)swap(a,b);
    while(b!=0)
    {
        a%=b;
        swap(a,b);           
    }    
    return a;
}

void sushubiao()
{
    memset(sushu,0,sizeof(sushu));
    memset(dabiao,0,sizeof(dabiao));
    dabiao[0]=1;
    dabiao[1]=1;
    int num;
    int i,j;  
    for(i=2;i<=1000000;i++)
        for(j=2;j<=1000000/i;j++)
            dabiao[j*i]=1;  
    
    j=0;
    for(i=2;i<=100000;i++)if(dabiao[i]==0){sushu[j]=i;j++;}
} 

int main()
{
    sushubiao();
    __int64 n;
    while(scanf("%I64d",&n) && n!=0)
    {
        int i=0;
        bool val=0,judge=0;
        if(n<0){n=-n;judge=1;}
        memset(dabiao1,0,sizeof(dabiao1));
        if(n==1){printf("1\n");continue;}
        while(n!=1)
        {
            if(n%sushu[i]==0){n/=sushu[i];dabiao1[i]++;}
            else i++;
            if(sushu[i]==0){val=1;break;}       
        }          
        if(val==1){printf("1\n");continue;}
        int gcds;
        for(i=0;i<100000;i++)
        {
            if(dabiao1[i]!=0){gcds=dabiao1[i];break;}               
        }
        for(;i<100000;i++)
        {
            if(dabiao1[i]!=0){gcds=gcd(gcds,dabiao1[i]);}              
        }
        if(judge==1)
        {
            while(gcds%2==0)gcds/=2;            
        }
        printf("%d\n",gcds);
    }
        
    system("pause");
    return 0;
}
