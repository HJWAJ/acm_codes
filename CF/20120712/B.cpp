#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
__int64 a[100005];
int main()
{
    __int64 n,i,sum=0;
    scanf("%I64d",&n);
    for(i=0;i<n;i++)scanf("%I64d",a+i);
    for(i=1;i<n;i++)
        if(a[i]<a[i-1])
            sum+=a[i-1]-a[i];
    printf("%I64d\n",sum);
    return 0;
}
