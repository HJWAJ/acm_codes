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
int main()
{
    int n,a[12],cnt=0,i,sum=0;
    scanf("%d",&n);
    for(i=0;i<12;i++)scanf("%d",a+i);
    sort(a,a+12);
    for(i=11;i>=0;i--)
    {
        if(sum>=n)
        {
            printf("%d\n",cnt);
            break;
        }
        sum+=a[i];
        cnt++;
    }
    if(i<0)
    {
        if(sum>=n)puts("12");
        else puts("-1");
    }
    return 0;
}
