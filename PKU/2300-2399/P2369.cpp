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
#include<deque>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<fstream>
using namespace std;
int a[1005];
bool bo[1005];
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    int n,i,j,cnt,ans;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)scanf("%d",a+i);
        ans=1;cnt=0;
        memset(bo,0,sizeof(bo));
        for(i=0;i<n;i++)
        {
            if(bo[a[i]-1])
            {
                cnt=0;
                continue;
            }
            else
            {
                j=a[i]-1;
                while(!bo[j])
                {
                    bo[j]=1;
                    j=a[j]-1;
                    cnt++;
                }
                ans=lcm(ans,cnt);
                cnt=0;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
