#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
int a[50][2];
int main()
{
    int t,n,tt=0,i;
    scanf("%d",&t);
    a[1][0]=a[1][1]=1;
    for(i=2;i<=45;i++)
    {
        a[i][0]=a[i-1][0]+a[i-1][1];
        a[i][1]=a[i-1][0];
    }
    while(t--)
    {
        tt++;
        scanf("%d",&n);
        printf("Scenario #%d:\n%d\n\n",tt,a[n][0]+a[n][1]);
    }
    return 0;
}
