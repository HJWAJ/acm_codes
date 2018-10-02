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
    __int64 k,b,n,t,cnt=0,ans=1;
    scanf("%I64d%I64d%I64d%I64d",&k,&b,&n,&t);
    while(ans<t)
    {
        ans*=k;
        ans+=b;
        cnt++;
    }
    cnt--;
    if(cnt>n)cnt=n;
    printf("%I64d\n",n-cnt);
    return 0;
}
