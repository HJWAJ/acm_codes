#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
/**
 *
 * 对4~12000，枚举每个数可以构成的符合的形式。
 * 构造方法是先分解数，变成大于1的因子乘积，再用1来补全。
 * 从小到大搜比较快。
 *
 */
int nk=0;
bool bo[12005];
void dfs(int cnt, int si, int di, int max)
{
    if(si<0)return;
    if(di==1)
    {
        cnt+=si;
        if(cnt<=12000 && !bo[cnt])
        {
            bo[cnt]=1;
            nk++;
        }
        return;
    }
    int i;
    for(i=min(max,di);i>=2;i--)
        if(di%i==0)
            dfs(cnt+1,si-i,di/i,i);
}
int main()
{
    int n=1,ans=0;
    while(nk<12000)
    {
        int i,big=n,last=nk;
        for(i=2;i<big;i++)
        {
            while(big%i==0)big/=i;
            if(big==1)big=i;
        }
        for(i=big;i<=n;i++)
            if(n%i==0)
                dfs(1,n-i,n/i,i);
        if(last!=nk)ans+=n;
        n++;
    }
    printf("%d\n",ans-1);
    return 0;
}
