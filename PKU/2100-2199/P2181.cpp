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
int a[200005],b[200005],c[200005];
int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)scanf("%d",a+i);
        b[0]=a[0],c[0]=0;
        for(i=1;i<n;i++)
        {
            b[i]=max(b[i-1],c[i-1]+a[i]);
            c[i]=max(c[i-1],b[i-1]-a[i]);
        }
        printf("%d\n",b[n-1]);
    }
    return 0;
}
