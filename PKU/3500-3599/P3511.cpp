#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int sushu[200000];
bool dabiao[1000001];

int sushubiao()
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
    for(i=2;i<=1000000;i++)if(dabiao[i]==0){sushu[j]=i;j++;}
    return j;
}

int main()
{
    int l,u,i,num,cnt,cnt1;
    num=sushubiao();
    while(scanf("%d%d",&l,&u) && !(l==-1 && u==-1))
    {
        cnt=cnt1=0;
        for(i=0;i<num;i++)
        {
            if(sushu[i]>=l && sushu[i]<=u)
            {
                cnt++;
                if(sushu[i]%4==1 || sushu[i]==2)cnt1++;               
            }                  
            if(sushu[i]>u)break;
        }                     
        printf("%d %d %d %d\n",l,u,cnt,cnt1);
    }    
    
    return 0;
}
