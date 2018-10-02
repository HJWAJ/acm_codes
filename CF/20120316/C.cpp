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
char s[1000005];
__int64 pos[1000005];
__int64 j=1,l;
__int64 calc(__int64 n)
{
    return n*(n+1)/2;
}
int main()
{
    __int64 n,len,i,ans=0;
    scanf("%I64d%s",&n,s);
    len=strlen(s);
    pos[0]=-1;
    for(i=0;i<len;i++)
        if(s[i]=='1')
            pos[j++]=i;
    pos[j++]=len;
    l=j;
    if(n==0)
    {
        for(i=0;i<l-1;i++)
            ans+=calc(pos[i+1]-pos[i]-1);
        printf("%I64d\n",ans);
        return 0;
    }
    for(i=1;i<l-n;i++)
        ans+=(pos[i]-pos[i-1])*(pos[i+n]-pos[i+n-1]);
    printf("%I64d\n",ans);
    return 0;
}
