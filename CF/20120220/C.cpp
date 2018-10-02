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
#include<sstream>
using namespace std;
const __int64 mod=1000000007LL;
char s[105][105];
set<char> ss;
int main()
{
    int n,m,i,j;
    __int64 ans=1LL;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(i=0;i<m;i++)
    {
        ss.clear();
        for(j=0;j<n;j++)ss.insert(s[j][i]);
        ans=ans*ss.size()%mod;
    }
    printf("%I64d\n",ans);
    return 0;
}
