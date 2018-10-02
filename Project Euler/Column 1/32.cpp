#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std;
vector<int> ok;
bool is(int a,int b,int c)
{
    bool bo[10];
    memset(bo,0,sizeof(bo));
    while(a)
    {
        if(!(a%10))return 0;
        if(bo[a%10])return 0;
        else bo[a%10]=1;
        a/=10;
    }
    while(b)
    {
        if(!(b%10))return 0;
        if(bo[b%10])return 0;
        else bo[b%10]=1;
        b/=10;
    }
    while(c)
    {
        if(!(c%10))return 0;
        if(bo[c%10])return 0;
        else bo[c%10]=1;
        c/=10;
    }
    return 1;
}
int main()
{
    int i,j,tmp,sum=0,cnt;
    ok.clear();
    for(i=1;i<10;i++)
        for(j=1234;j<=9876;j++)
        {
            tmp=i*j;
            if(is(i,j,tmp))ok.push_back(tmp);
        }
    for(i=12;i<=98;i++)
        for(j=123;j<=987;j++)
        {
            tmp=i*j;
            if(is(i,j,tmp))ok.push_back(tmp);
        }
    sort(ok.begin(),ok.end());
    unique(ok.begin(),ok.end());
    cnt=ok.size();
    for(i=1;i<cnt;i++)
        if(ok[i]<=ok[i-1])
        {
            cnt=i;
            break;
        }
    for(i=0;i<cnt;i++)sum+=ok[i];
    printf("%d\n",sum);
    return 0;
}
