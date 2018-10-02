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
using namespace std;
int a[100100];
int main()
{
    int n,x,i,cnt=0,mid;
    scanf("%d%d",&n,&x);
    for(i=1;i<=n;i++)scanf("%d",a+i);
    for(i=1;i<=n;i++)
        if(a[i]==x)break;
    if(i==n+1)
    {
        a[n+1]=x;
        n++;
        cnt++;
    }
    sort(a+1,a+n+1);
    //for(i=1;i<=n;i++)cout<<a[i]<<endl;
    //cout<<n<<endl;
    mid=(n+1)/2;
    if(a[mid]==x)printf("%d\n",cnt);
    else
    {
        if(a[mid]>x)
        {
            i=mid;
            while(a[i]>x)i--;
            if(n&1)cnt+=(n-i-i);
            else cnt+=(n+1-i-i);
            printf("%d\n",cnt);
        }
        else
        {
            i=mid;
            while(a[i]<x)i++;
            cnt+=(i+i-n-1);
            printf("%d\n",cnt);
        }
    }
    return 0;
}
