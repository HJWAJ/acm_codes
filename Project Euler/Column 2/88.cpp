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
 * ��4~12000��ö��ÿ�������Թ��ɵķ��ϵ���ʽ��
 * ���췽�����ȷֽ�������ɴ���1�����ӳ˻�������1����ȫ��
 * ��С�����ѱȽϿ졣
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
