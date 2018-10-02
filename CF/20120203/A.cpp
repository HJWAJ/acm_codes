#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
using namespace std;
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
    int k,l,m,n,d;
    int ans=0;
    scanf("%d%d%d%d%d",&k,&l,&m,&n,&d);
    ans+=d/k;
    ans+=d/l;
    ans+=d/m;
    ans+=d/n;
    ans-=d/lcm(k,l);
    ans-=d/lcm(k,m);
    ans-=d/lcm(k,n);
    ans-=d/lcm(l,m);
    ans-=d/lcm(l,n);
    ans-=d/lcm(n,m);
    ans+=d/lcm(k,lcm(l,m));
    ans+=d/lcm(k,lcm(l,n));
    ans+=d/lcm(k,lcm(n,m));
    ans+=d/lcm(n,lcm(l,m));
    ans-=d/lcm(k,lcm(l,lcm(m,n)));
    printf("%d\n",ans);
    return 0;
}
