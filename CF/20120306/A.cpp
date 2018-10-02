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
int a[105];
int main()
{
    int n,i,sum=0,sum0=0,cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    for(i=0;i<n;i++)sum+=a[i];
    sum/=2;
    for(i=n-1;i>=0;i--)
    {
        sum0+=a[i];
        cnt++;
        if(sum0>sum)break;
    }
    printf("%d\n",cnt);
    return 0;
}
