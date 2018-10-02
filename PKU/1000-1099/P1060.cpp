#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int t,len[3],a[3][1005],i,j,tmp[2005],num;
    scanf("%d",&t);
    while(t--)
    {
        memset(tmp,0,sizeof(tmp));
        for(i=0;i<3;i++)
        {
            scanf("%d",len+i);
            for(j=0;j<len[i];j++)scanf("%d",&a[i][j]);                
        }
        for(i=0;i<len[0];i++)
            for(j=0;j<len[1];j++)
                tmp[i+j]^=(a[0][i]*a[1][j]);
        /*        
        printf("%d",len[0]+len[1]-1);
        for(i=0;i<len[0]+len[1]-1;i++)printf(" %d",tmp[i]);
        printf("\n");
        */
        for(i=0;i<len[0]+len[1]-len[2];i++)
        {
            if(tmp[i]!=0)
            {
                for(j=0;j<len[2];j++)tmp[i+j]^=a[2][j];             
            }
        }
        i=0;
        while(tmp[i]==0)i++;
        num=len[0]+len[1]-1-i;
        printf("%d",num);
        for(;i<len[0]+len[1]-1;i++)printf(" %d",tmp[i]);
        printf("\n");
    }
    
    //system("pause");
    return 0;
}
