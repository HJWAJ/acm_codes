#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct mat
{
    long long int a[5][5],size;
    mat()
    {
        size=0;
        memset(a,0,sizeof(a));
    }
};
long long int sushu[50005];
bool dabiao[200005];
void print(mat m)
{
    int i,j;
    printf("%d\n",m.size);
    for(i=0;i<m.size;i++)
    {
        for(j=0;j<m.size;j++)printf("%d ",m.a[i][j]);
        printf("\n");
    }
}
void sushubiao()
{
    memset(sushu,0,sizeof(sushu));
    memset(dabiao,0,sizeof(dabiao));
    dabiao[0]=1;
    dabiao[1]=1;
    long long int num;
    long long int i,j,flag=0;
    for(i=2;i<=50000;i++)
        if(dabiao[i]==0)
        {
            sushu[flag++]=i;
            for(j=2;j<=50000/i;j++)dabiao[j*i]=1;
        }
}
int divide(long long int n,long long int p[],long long int a[])
{
    long long int sq=(long long int)(sqrt(double(n)));
    int flag=0,num=0;
    while(1)
    {
        if(n==1)break;
        if(sushu[flag]>sq)
        {
            p[num]=n;
            a[num++]=1;
            break;
        }
        if(n%sushu[flag]!=0)
        {
            flag++;
            continue;
        }
        p[num]=sushu[flag];
        a[num++]=1;
        n/=sushu[flag];
        while(n%sushu[flag]==0)
        {
            n/=sushu[flag];
            a[num-1]++;
        }
        flag++;
    }
    return num;
}
mat multi(mat m1,mat m2,long long int mod)
{
    mat ans=mat();
    int i,j,k;
    for(i=0;i<m1.size;i++)
        for(j=0;j<m1.size;j++)
            if(m1.a[i][j])
                for(k=0;k<m1.size;k++)
                {
                    ans.a[i][k]+=(m1.a[i][j]*m2.a[j][k]%mod);
                    ans.a[i][k]%=mod;
                }
    ans.size=m1.size;
    return ans;
}
mat quickmulti(mat m,long long int n,long long int mod)
{
    mat ans=mat();
    int i;
    for(i=0;i<m.size;i++)ans.a[i][i]=1LL;
    ans.size=m.size;
    while(n)
    {
        if(n&1LL)ans=multi(m,ans,mod);
        m=multi(m,m,mod);
        n>>=1LL;
    }
    return ans;
}
int main()
{
    long long int A,B,i,p[1005],a[1005],ans=1LL,n,mod=9901LL;
    mat m=mat(),ansm=mat();
    m.size=ansm.size=2LL;
    sushubiao();
    scanf("%lld%lld",&A,&B);
    n=divide(A,p,a);
    for(i=0;i<n;i++)a[i]*=B;
    //for(i=0;i<n;i++)cout<<p[i]<<' '<<a[i]<<endl;
    for(i=0;i<n;i++)
    {
        m.a[0][0]=m.a[0][1]=1LL;
        m.a[1][0]=0LL;
        m.a[1][1]=p[i];
        ansm.a[1][0]=0LL;
        ansm.a[0][0]=ansm.a[1][1]=ansm.a[0][1]=1LL;
        ansm=multi(ansm,quickmulti(m,a[i],mod),mod);
        //print(quickmulti(m,a[i],mod));
        ans*=ansm.a[0][1];
        ans%=mod;
    }
    printf("%lld\n",ans);
    return 0;
}
