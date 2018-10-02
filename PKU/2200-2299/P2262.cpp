#include<iostream>
#include<cstring>
using namespace std;

int sushu[100000];
bool dabiao[1000001];

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
    for(i=2;i<=1000000;i++)if(dabiao[i]==0){sushu[j]=i;j++;}
} 

int main()
{
    sushubiao();
    int n;
    while(scanf("%d",&n) && n!=0)
    {
        int i=0;
        for(i=1;n>(sushu[i]/2+1);i++)
        {
            if(dabiao[n-sushu[i]]==0)
            {
                printf("%d = %d + %d\n",n,sushu[i],n-sushu[i]); 
                break;
            }            
        }             
    }    
    
    system("pause");
    return 0;
}
