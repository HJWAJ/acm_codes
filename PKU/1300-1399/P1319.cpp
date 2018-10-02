#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const double PI=acos(-1.0);
int solve(double r,double c)
{
    int ans,n1,n2,row;
    if(c<2.0)return 0;
    ans=n1=int(r/2.0);
    c-=2.0;
    if(r/2.0 - int(r/2.0) >= 0.5)n2=n1;
    else n2=n1-1;
    row=int(c/sqrt(3.0));
    if(row&1)
    {
        row--;
        ans+=n2;
    }
    ans+=(n1+n2)*row/2;
    return ans;
}
int main()
{
    double r,c;
    int n,nn,nnn;
    while(scanf("%lf%lf",&r,&c)!=EOF)
    {
        n=int(r)*int(c);
        r*=2.0;c*=2.0;
        nn=solve(r,c);
        nnn=solve(c,r);
        if(nnn>nn)nn=nnn;
        if(n>=nn)printf("%d grid\n",n);
        else printf("%d skew\n",nn);
    }
    return 0;
}
