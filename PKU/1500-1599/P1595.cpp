#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<algorithm>
#include<cstdlib>
using namespace std;
int sushu[10000];
bool dabiao[10001];
int sushubiao()//+++++¡ª¡ª
{
    memset(sushu,0,sizeof(sushu));
    memset(dabiao,0,sizeof(dabiao));
    dabiao[0]=1;
    dabiao[1]=0;
    sushu[0]=1;
    int num;
    int i,j,flag=1;
    for(i=2;i<=10000;i++)
        if(dabiao[i]==0)
        {
            sushu[flag++]=i;
            for(j=2;j<=10000/i;j++)dabiao[j*i]=1;
        }
    return flag;
}
int main()
{
    int c,n,num,l,u,i;
    sushubiao();
    while(scanf("%d%d",&n,&c)!=EOF)
    {
        printf("%d %d:",n,c);
        i=0;
        while(sushu[i]<=n)i++;
        num=i;
        if(2*c-1>=num)
            for(i=0;i<num;i++)
                printf(" %d",sushu[i]);
        else
            if(num&1)
                for(i=num/2+1-c;i<=num/2+c-1;i++)
                    printf(" %d",sushu[i]);
            else
                for(i=num/2-c;i<=num/2+c-1;i++)
                    printf(" %d",sushu[i]);
        printf("\n\n");
    }
    return 0;
}
