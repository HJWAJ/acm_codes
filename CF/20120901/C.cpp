#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int a[100005],b[100005];
int main()
{
    int n,i,cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
        b[i]=a[i];
    }
    sort(a,a+n);
    for(i=0;i<n;i++)
        if(a[i]!=b[i])
            cnt++;
    if(cnt<3)puts("YES");
    else puts("NO");
    return 0;
}