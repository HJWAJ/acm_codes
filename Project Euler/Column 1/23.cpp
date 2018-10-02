#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int a[30001];
int bo[30001];
bool bo2[30001];
int flag=0;
int abun(int n)
{
    int i,nn=sqrt(n),res=0;
    for(i=1;i<=nn;i++)
    {
        if(n%i==0)
        {
            res+=i;
            res+=n/i;
        }
    }
    if(nn*nn==n)res-=nn;
    res-=n;
    return res;
}
int main()
{
    int i,j,k,sum=0;
    memset(bo,-1,sizeof(bo));
    memset(bo2,0,sizeof(bo2));
    for(i=10;i<=28123;i++)
        if(abun(i)>i)
        {
            a[flag++]=i;
            bo2[i]=1;
        }
    //cout<<flag<<endl;
    for(k=1;k<=28123;k++)
    {
        for(j=0;j<flag && k>a[j];j++)
            if(bo2[k-a[j]])break;
        if(j==flag || k<=a[j])sum+=k;
    }
    printf("%d\n",sum);
    return 0;
}
