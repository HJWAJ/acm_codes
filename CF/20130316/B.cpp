#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<map>
#include<string>
#include<ctime>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int a,b,d,ans,i;
    double sq;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        ans=0;
        d=gcd(a,b);
        sq=sqrt(d*1.0);
        for(i=1;i<sq;i++)
            if(d%i==0)
                ans+=2;
        if(i*i==d)ans++;
        printf("%d\n",ans);
    }
    return 0;
}
