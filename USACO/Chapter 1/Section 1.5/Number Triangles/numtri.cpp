/*
ID: hjw00002
PROG: numtri
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int max(int a,int b)
{
    return a>b?a:b;    
}

int main()
{
    freopen("numtri.in","r",stdin);
    freopen("numtri.out","w",stdout);
    int a[1001][1001],i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<=i;j++)
            scanf("%d",&a[i][j]);
    for(i=n-2;i>=0;i--)
        for(j=0;j<=i;j++)
            a[i][j]=max(a[i][j]+a[i+1][j],a[i][j]+a[i+1][j+1]);
    printf("%d\n",a[0][0]);
    
    //system("pause");
    return 0;
}
