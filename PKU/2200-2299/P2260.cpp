#include<iostream>
#include<cstdio>
#include<cstring>

int main()
{
    int n,i,j,row[100],col[100],cntrow,cntcol;
    bool val[100][100];
    while(scanf("%d",&n)!=EOF && n!=0)
    {
        memset(row,0,400);
        memset(col,0,400);
        cntrow=cntcol=0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                scanf("%d",&val[i][j]);
                row[i]+=val[i][j];
                col[j]+=val[i][j];
            }
        for(i=0;i<n;i++){row[i]%=2;cntrow+=row[i];}
        for(i=0;i<n;i++){col[i]%=2;cntcol+=col[i];}
        if(cntrow>1 || cntcol>1){printf("Corrupt\n");continue;}
        if(cntrow==1 && cntcol==1)
        {
            for(i=0;i<n;i++)if(row[i]==1)break;
            for(j=0;j<n;j++)if(col[j]==1)break;
            printf("Change bit (%d,%d)\n",i+1,j+1);
            continue;
        }
        if(cntrow^cntcol==1)printf("Corrupt\n");
        else printf("OK\n");
    }
    
    system("pause");
    return 0; 
}
