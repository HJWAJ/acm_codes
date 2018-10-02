#include<iostream>
#include<cstdio>
#include<cstring>
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

int main()
{
    sushubiao();
    int m,n,i;
    scanf("%d%d",&m,&n);
    for(i=0;i<50000;i++)
    {
        if(sushu[i]==m)
        {
            if(sushu[i+1]==n)printf("YES\n");
            else printf("NO\n");
            break;               
        }                    
    }
    
    //system("pause");
    return 0;
}
