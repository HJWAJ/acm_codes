#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
const long long int MOD=1000000007LL;
struct mat//正方形矩阵结构体，a表示内容，size大小
{
    long long int a[3][3],size;
    mat()
    {
        size=0;
        memset(a,0,sizeof(a));
    }
};
void print(mat m)//输出矩阵信息，debug用
{
    int i,j;
    printf("%lld\n",m.size);
    for(i=0;i<m.size;i++)
    {
        for(j=0;j<m.size;j++)printf("%lld ",m.a[i][j]);
        printf("\n");
    }
}
mat multi(mat m1,mat m2,int mod)//两个相等矩阵的乘法，对于稀疏矩阵，有0处不用运算，n^3优化为n^2
{
    mat ans=mat();
    int i,j,k;
    for(i=0;i<m1.size;i++)
        for(j=0;j<m1.size;j++)
            if(m1.a[i][j])//稀疏矩阵优化
                for(k=0;k<m1.size;k++)
                {
                    ans.a[i][k]+=m1.a[i][j]*m2.a[j][k]%mod;
                    ans.a[i][k]%=mod;
                }
    ans.size=m1.size;
    return ans;
}
mat quickmulti(mat m,int n,long long int mod)//二分快速幂
{
    mat ans=mat();
    int i;
    for(i=0;i<m.size;i++)ans.a[i][i]=1LL;
    ans.size=m.size;
    while(n)
    {
        if(n&1)ans=multi(ans,m,mod);
        m=multi(m,m,mod);
        n>>=1;
    }
    return ans;
}
int main()
{
    //freopen("Triple.in","r",stdin);
    //freopen("Triple.out","w",stdout);
    int t,n;
    mat m,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==1)
        {
            puts("1");
            continue;
        }
        if(n==2)
        {
            puts("2");
            continue;
        }
        if(n==3)
        {
            puts("3");
            continue;
        }
        m=mat();
        ans=mat();
        m.size=3;
        m.a[0][0]=3;m.a[0][1]=1;m.a[0][2]=0;
        m.a[1][0]=-3;m.a[1][1]=0;m.a[1][2]=1;
        m.a[2][0]=2;m.a[2][1]=0;m.a[2][2]=0;
        ans.size=3;
        ans.a[0][0]=3;ans.a[0][1]=2;ans.a[0][2]=1;
        ans=multi(ans,quickmulti(m,n-3,MOD),MOD);
        printf("%lld\n",(ans.a[0][0]+MOD)%MOD);
    }
    return 0;
}
