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
bool bo[1000005];
inline int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
inline bool coprime(int a,int b,int c)
{
    if(gcd(a,b)==1 && gcd(b,c)==1 && gcd(a,c)==1)return 1;
    return 0;
}
int main()
{
    int n,i,j,ans1,ans2,x,y,z,k;
    while(scanf("%d",&n)!=EOF)
    {
        ans1=ans2=0;
        memset(bo,0,sizeof(bo));
        for(i=1;i*i<=n;i++)
            for(j=1;j<i;j++)
                if(i*i+j*j<=n)
                {
                    z=i*i+j*j;
                    if(2*i*j>i*i-j*j)
                    {
                        x=i*i-j*j;
                        y=2*i*j;
                    }
                    else
                    {
                        x=2*i*j;
                        y=i*i-j*j;
                    }
                    if(coprime(x,y,z))
                    {
                        ans1++;
                        for(k=1;k*z<=n;k++)bo[k*x]=bo[k*y]=bo[k*z]=1;
                    }
                }
        for(i=1;i<=n;i++)
            if(!bo[i])ans2++;
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
