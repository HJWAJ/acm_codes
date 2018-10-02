/*
ID: hjw00002
PROG: subset
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

int f[100][2000];

int main()
{    
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    int n,i,j,sum;
    scanf("%d",&n);
    sum=n*(n+1)/2;
    if(sum&1){printf("0\n");goto label;}
    memset(f,0,sizeof(f));
    f[1][0]=f[1][1]=1;
    for(i=2;i<=n;i++)
        for(j=0;j<=sum;j++)
        {
            if(j<=i)f[i][j]+=f[i-1][j];
            else f[i][j]=f[i-1][j]+f[i-1][j-i];
        }
    printf("%d\n",f[n][sum/2]);
    
    label:;
    //system("pause");
    return 0;
}
