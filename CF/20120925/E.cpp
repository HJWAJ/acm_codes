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
struct mat
{
    __int64 a[2][2],size;
    mat()
    {
        size=0;
        memset(a,0,sizeof(a));
    }
};
mat multi(mat m1,mat m2,__int64 mod)
{
    mat ans=mat();
    __int64 i,j,k;
    for(i=0;i<m1.size;i++)
        for(j=0;j<m2.size;j++)
            if(m1.a[i][j])
            {
                for(k=0;k<m1.size;k++)ans.a[i][k]+=m1.a[i][j]*m2.a[j][k]%mod;
                ans.a[i][k]%=mod;
            }
    ans.size=m1.size;
    return ans;
}
mat quickmulti(mat m,__int64 n,__int64 mod)
{
    mat ans=mat();
    __int64 i;
    for(i=0;i<m.size;i++)ans.a[i][i]=1;
    ans.size=m.size;
    while(n)
    {
        if(n&1)ans=multi(m,ans,mod);
        m=multi(m,m,mod);
        n>>=1;
    }
    return ans;
}
__int64 fib(__int64 n,__int64 mod)
{
    mat m=mat();
    m.size=2;
    m.a[0][0]=m.a[0][1]=m.a[1][0]=1;
    m.a[1][1]=0;
    m=quickmulti(m,n,mod);
    return m.a[0][1];
}
int main()
{
    __int64 m,l,r,k,n;
    scanf("%I64d%I64d%I64d%I64d",&m,&l,&r,&k);
    n=(r+1-l)/k;
    printf("%I64d\n",fib(n,m));
    return 0;
}
