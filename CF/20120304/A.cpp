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
int a[55];
int main()
{
    int n,k,i;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    if(a[n-k]>0)
    {
        for(i=n-k;i>=0;i--)
            if(a[i]!=a[n-k])
                break;
        printf("%d\n",n-i-1);
    }
    else
    {
        for(i=n-k;i<n;i++)
            if(a[i]>0)
                break;
        printf("%d\n",n-i);
    }
    return 0;
}
