#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[10005],f[10005],st[10005];
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",a+i);
    for(i=0;i<n;i++)
        if(a[i]>=0)
            break;
    if(i==n)
    {
        printf("0 %d %d\n",a[0],a[n-1]);
        return 0;
    }
    f[0]=a[0];
    for(i=1;i<n;i++)
    {
        if(f[i-1]<0)
        {
            f[i]=a[i];
            st[i]=i;
        }
        else
        {
            f[i]=a[i]+f[i-1];
            st[i]=st[i-1];
        }
    }
    int ans=-1,start,end;
    for(i=0;i<n;i++)
        if(f[i]>ans)
        {
            ans=f[i];
            start=st[i];
            end=i;
        }
    printf("%d %d %d\n",ans,a[start],a[end]);
    return 0;
}
