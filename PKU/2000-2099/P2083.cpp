#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[7][730][730];
int main()
{
    int i,j,k,n,a[7]={1,3,9,27,81,243,729};
    memset(s,' ',sizeof(s));
    s[0][0][0]='X';
    for(i=1;i<7;i++)
    {
        for(j=0;j<a[i-1];j++)
            for(k=0;k<a[i-1];k++)
            {
                s[i][j][k]=s[i-1][j][k];
                s[i][j+2*a[i-1]][k]=s[i-1][j][k];
                s[i][j][k+2*a[i-1]]=s[i-1][j][k];
                s[i][j+2*a[i-1]][k+2*a[i-1]]=s[i-1][j][k];
                s[i][j+a[i-1]][k+a[i-1]]=s[i-1][j][k];
            }
    }
    while(scanf("%d",&n) && n!=-1)
    {
        for(i=0;i<a[n-1];i++)
        {
            for(j=0;j<a[n-1];j++)printf("%c",s[n-1][i][j]);
            printf("\n");
        }
        printf("-\n");
    }
    return 0;
}
