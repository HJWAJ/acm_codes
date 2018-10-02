#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <memory.h>
using namespace std;
__int64 divi[100005];
__int64 prime[50000];
bool bo[50001];
__int64 p[100005],a[100005];
int prime_table()
{
    int i,j,flag=0;
    memset(bo,0,sizeof(bo));
    bo[0]=bo[1]=1;
    for(i=2;i<=50000;i++)
        if(!bo[i])
        {
            prime[flag++]=i;
            j=i+i;
            for(;j<=50000;j+=i)bo[j]=1;
        }
    return flag;
}
int divided(__int64 n,__int64 p[],__int64 a[])
{
    __int64 sq=(__int64)(sqrt(double(n)));
    int flag=0,num=0;
    while(1)
    {
        if(n==1)break;
        if(prime[flag]>sq)
        {
            p[num]=n;
            a[num++]=1;
            break;
        }
        if(n%prime[flag]!=0)
        {
            flag++;
            continue;
        }
        p[num]=prime[flag];
        a[num++]=1;
        n/=prime[flag];
        while(n%prime[flag]==0)
        {
            n/=prime[flag];
            a[num-1]++;
        }
        flag++;
    }
    return num;
}
__int64 divide(__int64 n)
{
    __int64 i,flag=0;
    for(i=1;i*i<n;i++)
    {
        if(n%i==0)
        {
            divi[flag++]=i;
            divi[flag++]=n/i;
        }
    }
    if(i*i==n)divi[flag++]=i;
    return flag;
}
__int64 eular(__int64 n)
{
    if(n==1)return 1;
    int flag=divided(n,p,a),i;
    //for(i=0;i<flag;i++)cout<<p[i]<<' '<<a[i]<<endl;
    for(i=0;i<flag;i++)
    {
        n/=p[i];
        n*=(p[i]-1);
    }
    return n;
}
int main()
{
    __int64 n,ans,flag,i;
    prime_table();
    while(scanf("%I64d",&n)!=EOF)
    {
        flag=divide(n);
        ans=0;
        for(i=0;i<flag;i++)
        {
            //cout<<divi[i]<<endl;
            ans+=divi[i]*eular(n/divi[i]);
        }
        printf("%I64d\n",ans);
    }
	return 0;
}
