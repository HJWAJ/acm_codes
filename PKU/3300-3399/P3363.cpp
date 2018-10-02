#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int m,n,r,c,i,j,ii,jj,cnt;
    char val[105][105];
    while(scanf("%d%d%d%d",&m,&n,&r,&c) && !(m==0 && n==0 && r==0 && c==0))
    {
        for(i=0;i<m;i++)scanf("%s",val[i]);
        cnt=0;
        for(i=0;i<=m-r;i++)
            for(j=0;j<=n-c;j++)
            {
                if(val[i][j]=='0')continue;
                else
                {
                    for(ii=0;ii<r;ii++)
                        for(jj=0;jj<c;jj++)
                        {
                            if(val[i+ii][j+jj]=='0')val[i+ii][j+jj]='1';
                            else val[i+ii][j+jj]='0';
                        }
                    cnt++;
                }
            }                              
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                if(val[i][j]=='1')goto label;
        label:if(i==m && j==n)printf("%d\n",cnt);
        else printf("-1\n");      
    }
    
    return 0;
}
