#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int a[5][5],t,x,y,i,j,k,bo=0;
    memset(a,0,sizeof(a));
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&x,&y);
        a[x-1][y-1]=a[y-1][x-1]=1;
    }
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            if(j!=i)
                for(k=0;k<5;k++)
                    if(k!=i && k!=j)
                        if(a[i][j] && a[i][k] && a[j][k])
                        {
                            bo++;
                            goto label1;
                        }
    label1:;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            if(j!=i)
                for(k=0;k<5;k++)
                    if(k!=i && k!=j)
                        if(!a[i][j] && !a[i][k] && !a[j][k])
                        {
                            bo++;
                            goto label;
                        }
    label:;
    if(bo)printf("WIN\n");
    else printf("FAIL\n");
    return 0;
}
