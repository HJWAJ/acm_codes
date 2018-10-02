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
#include<ctime>
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
char s[1005],t[1005];
int main()
{
    int n,l1,l2,d,i,j,k,cnt1=0,cnt2=0,ans1=0,ans2=0,rest;
    scanf("%d%s%s",&n,s,t);
    l1=strlen(s);
    l2=strlen(t);
    d=lcm(l1,l2);
    for(i=0,j=0,k=0;i<d;i++,j++,k++)
    {
        if(j==l1)j=0;
        if(k==l2)k=0;
        if(s[j]=='R' && t[k]=='S')cnt1++;
        else if(s[j]=='S' && t[k]=='P')cnt1++;
        else if(s[j]=='P' && t[k]=='R')cnt1++;
        else if(t[k]=='R' && s[j]=='S')cnt2++;
        else if(t[k]=='S' && s[j]=='P')cnt2++;
        else if(t[k]=='P' && s[j]=='R')cnt2++;
    }
    ans1=n/d*cnt1;
    ans2=n/d*cnt2;
    rest=n%d;
    cnt1=cnt2=0;
    for(i=0,j=0,k=0;i<rest;i++,j++,k++)
    {
        if(j==l1)j=0;
        if(k==l2)k=0;
        if(s[j]=='R' && t[k]=='S')cnt1++;
        else if(s[j]=='S' && t[k]=='P')cnt1++;
        else if(s[j]=='P' && t[k]=='R')cnt1++;
        else if(t[k]=='R' && s[j]=='S')cnt2++;
        else if(t[k]=='S' && s[j]=='P')cnt2++;
        else if(t[k]=='P' && s[j]=='R')cnt2++;
    }
    ans1+=cnt1;
    ans2+=cnt2;
    printf("%d %d\n",ans2,ans1);
    return 0;
}
