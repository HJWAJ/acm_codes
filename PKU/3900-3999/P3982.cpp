#include<stdio.h>
#include<string.h>

int result[3][100];

void itoa(int a,int num[])
{
    int i=0;
    memset(num,0,sizeof(num));
    while(a)
    {
        num[i]=a%10;
        a/=10;
        i++;
    }  
}

void Add(int *a,int *b,int *c,int num[])
{
    int i;
    for(i=0;i<99;i++)num[i]=a[i]+b[i]+c[i];
    for(i=0;i<99;i++)
    {
        num[i+1]+=(num[i]/10);
        num[i]%=10;
    }
}

int main()
{
    int a,b,c,i;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        memset(result,0,sizeof(result));
        itoa(a,result[0]);
        itoa(b,result[1]);
        itoa(c,result[2]);
        for(i=3;i<=99;i++)
        {
            Add(result[i%3],result[(i+1)%3],result[(i+2)%3],result[i%3]);                  
        }                                    
        i=99;
        while(result[0][i]==0)i--;
        for(;i>=0;i--)printf("%d",result[0][i]);
        printf("\n");
    }
    
    return 0;
}
