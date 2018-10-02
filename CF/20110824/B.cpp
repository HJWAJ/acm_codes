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
int a[100005];
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    for(i=0;i<n-1;i++)
    {
        if(a[i+1]==a[i])continue;
        if(a[i+1]<a[i]*2)
        {
            puts("YES");
            break;
        }
    }
    if(i==n-1)puts("NO");
    return 0;
}
