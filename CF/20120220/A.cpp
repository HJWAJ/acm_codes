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
set<int> myset;
char s[105][105];
int main()
{
    memset(s,0,sizeof(s));
    myset.clear();
    int n,m,i,j;
    char max;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(i=0;i<m;i++)
    {
        max='0';
        for(j=0;j<n;j++)
            if(s[j][i]>=max)
                max=s[j][i];
        for(j=0;j<n;j++)
            if(s[j][i]==max)
                myset.insert(j);
    }
    printf("%d\n",myset.size());
    return 0;
}
