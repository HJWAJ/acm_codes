#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
#include<ctime>
using namespace std;
__int64 a[100005];
int main()
{
    __int64 n,m,b,q,i,sa=0,sb=0;
    scanf("%I64d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%I64d",&b);
        a[b]=i+1;
    }
    scanf("%I64d",&m);
    while(m--)
    {
        scanf("%I64d",&q);
        sa+=a[q];
        sb+=n+1-a[q];
    }
    printf("%I64d %I64d\n",sa,sb);
    return 0;
}
