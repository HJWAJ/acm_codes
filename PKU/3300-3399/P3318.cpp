#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
struct mat
{
    int a[505][505];
}m1,m2,m3;
int n;
bool multi()
{
    mat ans;
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            ans.a[i][j]=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(m1.a[i][j])//Ï¡Êè¾ØÕóÓÅ»¯
                for(k=0;k<n;k++)
                    ans.a[i][k]+=m1.a[i][j]*m2.a[j][k];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(ans.a[i][j]!=m3.a[i][j])
                return 0;
    return 1;
}
int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&m1.a[i][j]);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&m2.a[i][j]);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&m3.a[i][j]);
        if(multi())puts("YES");
        else puts("NO");
    }
    return 0;
}
