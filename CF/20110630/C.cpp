#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int min(int a,int b)
{
    return a<b?a:b;
}
int main()
{
    int n,m,s,t,ans=3;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    if(m==1)ans=1;
    else if(s/m==t/m)ans=1;
    else if(s/m==t/m-1)
    {
        ans=2;
        if(s%m==1 && t%m==0)ans=1;
        if(s%m==1 && t==n)ans=1;
    }
    else
    {
        if(s%m==1 && t%m==0)ans=1;
        if((s%m==1) && t!=n)ans=min(2,ans);
        if((s%m==1) && t==n)ans=min(1,ans);
        if(t%m==0)ans=min(2,ans);
        if(s%m==0 && t%m==m-1)ans=min(2,ans);
        if(s%m==t%m+1)ans=min(2,ans);
        if(t==n && s%m!=1)ans=min(2,ans);
    }
    printf("%d\n",ans);
    return 0;
}
