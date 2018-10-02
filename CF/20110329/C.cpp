#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int sushu[100000],a[100005],val[100005];
bool dabiao[200001];

void sushubiao()
{
    memset(sushu,0,sizeof(sushu));
    memset(dabiao,0,sizeof(dabiao));
    dabiao[0]=1;
    dabiao[1]=1;
    int num;
    int i,j;  
    for(i=2;i<=100000;i++)
        for(j=2;j<=100000/i;j++)
            dabiao[j*i]=1;  
    
    j=0;
    for(i=2;i<=100000;i++)if(dabiao[i]==0){sushu[j]=i;j++;}
} 

bool check(int n,int ini,int k,int val[])
{
    int i;
    for(i=ini;i<n;i+=k)
        if(val[i]==0)return 0;
    return 1;     
}

int main()
{
    sushubiao();
    int n,i,j,nn,num;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",val+i);
    nn=n;
    i=j=0;
    while(nn%2==0)nn/=2;
    while(nn!=1)
    {
        if(nn%sushu[i]==0)
        {
            a[j]=sushu[i];
            j++;
            while(nn%sushu[i]==0)nn/=sushu[i];
        }
        i++;        
    }
    num=j;
    for(i=0;i<num;i++)
    {
        nn=n/a[i];
        for(j=0;j<nn;j++)
            if(check(n,j,nn,val))
            {
                printf("YES\n");
                goto label;                       
            }
    }
    printf("NO\n");
    label:;
    
    //system("pause");
    return 0;
}
