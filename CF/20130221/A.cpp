#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<ctime>
using namespace std;
int g[5][5];
int main()
{
    int i,j,a;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            g[i+1][j+1]=1;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            scanf("%d",&a);
            g[i+1][j+1]+=a;
            g[i][j+1]+=a;
            g[i+1][j]+=a;
            g[i+2][j+1]+=a;
            g[i+1][j+2]+=a;
        }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)printf("%d",g[i+1][j+1]%2);
        puts("");
    }
    return 0;
}
