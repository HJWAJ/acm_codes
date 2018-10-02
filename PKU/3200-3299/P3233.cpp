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
struct mat//矩阵结构体，a表示内容，size大小
{
    int a[105][105],size;
    mat()
    {
        size=0;
        memset(a,0,sizeof(a));
    }
};
void print(mat m)//输出矩阵信息，debug用
{
    int i,j;
    printf("%d\n",m.size);
    for(i=0;i<m.size;i++)
    {
        for(j=0;j<m.size;j++)printf("%d ",m.a[i][j]);
        printf("\n");
    }
}
int mult(int a,int b,int mod)//自己写大数乘法，利用位运算有效避免int64或者高精度，这里a,b,mod只要不超过2^30就不会出问题
{
    int exp=a%mod,res=0;
    while(b)
    {
        if(b&1)
        {
            res+=exp;
            if(res>=mod)res-=mod;
        }
        exp<<=1;
        if(exp>=mod)exp-=mod;
        b>>=1;
    }
    return res;
}
mat multi(mat m1,mat m2,int mod)//两个相等矩阵的乘法，对于稀疏矩阵，有0处不用运算的优化
{
    mat ans=mat();
    int i,j,k;
    for(i=0;i<m1.size;i++)
        for(j=0;j<m1.size;j++)
            if(m1.a[i][j])//稀疏矩阵优化
                for(k=0;k<m1.size;k++)
                {
                    ans.a[i][k]+=(m1.a[i][j]*m2.a[j][k]%mod);
                    ans.a[i][k]%=mod;
                }
    ans.size=m1.size;
    return ans;
}
mat quickmulti(mat m,int n,int mod)//二分快速幂
{
    mat ans=mat();
    int i;
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
int main()
{
    int n,k,mod,i,j;
    mat ans=mat(),m=mat();
    scanf("%d%d%d",&n,&k,&mod);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&m.a[i][j]);
    ans.size=m.size=2*n;
    for(i=0;i<n;i++)
    {
        ans.a[i][i]=1;
        ans.a[i+n][i]=1;
        ans.a[i][i+n]=1;
        m.a[i+n][i]=1;
        m.a[i+n][i+n]=1;
    }
    m=quickmulti(m,k,mod);
    ans=multi(ans,m,mod);
    for(i=0;i<n;i++)
    {
        ans.a[i][i]+=(mod-1);
        ans.a[i][i]%=mod;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)printf("%d ",ans.a[i][j]);
        printf("\n");
    }
	return 0;
}
