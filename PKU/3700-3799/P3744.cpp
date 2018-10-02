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
    double a[105][105];
    int size;
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
        for(j=0;j<m.size;j++)printf("%lf ",m.a[i][j]);
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
mat multi(mat m1,mat m2)//两个相等矩阵的乘法，对于稀疏矩阵，有0处不用运算的优化
{
    mat ans=mat();
    int i,j,k;
    for(i=0;i<m1.size;i++)
        for(j=0;j<m1.size;j++)
            //if(m1.a[i][j])//稀疏矩阵优化
                for(k=0;k<m1.size;k++)
                {
                    ans.a[i][k]+=m1.a[i][j]*m2.a[j][k];
                }
    ans.size=m1.size;
    return ans;
}
mat quickmulti(mat m,int n)//二分快速幂
{
    mat ans=mat();
    int i;
    for(i=0;i<m.size;i++)ans.a[i][i]=1.0;
    ans.size=m.size;
    while(n)
    {
        if(n&1)ans=multi(m,ans);
        m=multi(m,m);
        n>>=1;
    }
    return ans;
}
int main()
{
    int n,a[15],i;
    double p,q,ans;
    while(scanf("%d%lf",&n,&p)!=EOF)
    {
        ans=1.0;
        q=1.0-p;
        for(i=0;i<n;i++)
        {
            scanf("%d",a+i);
            a[i]--;
        }
        sort(a,a+n);
        if(a[0]==0)
        {
            puts("0.0000000");
            continue;
        }
        else
        {
            for(i=0;i<n-1;i++)
                if(a[i]==a[i+1]-1)
                {
                    puts("0.0000000");
                    break;
                }
            if(i<n-1)continue;
        }
        mat dp=mat();
        dp.size=2;
        dp.a[0][0]=p;
        dp.a[0][1]=1.0;
        mat m=mat();
        m.size=2;
        m.a[0][0]=p;
        m.a[1][0]=q;
        m.a[0][1]=1.0;
        if(a[0]==1)dp.a[0][0]=1.0;
        else dp=multi(dp,quickmulti(m,a[0]-2));
        ans*=(dp.a[0][0]*q);
        for(i=1;i<n;i++)
        {
            dp=mat();
            dp.size=2;
            dp.a[0][0]=p;
            dp.a[0][1]=1.0;
            m=mat();
            m.size=2;
            m.a[0][0]=p;
            m.a[1][0]=q;
            m.a[0][1]=1.0;
            //cout<<a[i]<<' '<<a[i-1]<<' '<<ans;
            if(a[i]-a[i-1]==2)dp.a[0][0]=1.0;
            else dp=multi(dp,quickmulti(m,a[i]-a[i-1]-3));
            //print(m);
            //cout<<' '<<dp.a[0][0]<<endl;
            ans*=(dp.a[0][0]*q);
        }
        printf("%.7lf\n",ans);
    }
	return 0;
}
