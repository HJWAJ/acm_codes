#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<deque>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<fstream>
using namespace std;
int a[1005];
int main()
{
    int n,m,h,s,s1,i;
    double ans;
    scanf("%d%d%d",&n,&m,&h);
    for(i=0;i<m;i++)scanf("%d",a+i);
    a[h-1]--;
    s=0;
    for(i=0;i<m;i++)s+=a[i];
    s1=s-a[h-1];
    if(s<n-1)puts("-1.0");
    else if(s1<n-1)puts("1.0");
    else
    {
        ans=1.0;
        for(i=0;i<a[h-1];i++)
        {
            ans*=(s-i-n+1);
            ans/=(s-i);
        }
        printf("%lf\n",1-ans);
    }
    return 0;
}
