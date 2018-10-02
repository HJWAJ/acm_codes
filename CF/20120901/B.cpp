#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool bo[15];
bool ok(int n)
{
    while(n)
    {
        if(bo[n%10])return 1;
        n/=10;
    }
    return 0;
}
int main()
{
    int n,nn,i,cnt=0;
    scanf("%d",&n);
    nn=n;
    memset(bo,0,sizeof(bo));
    while(nn)
    {
        bo[nn%10]=1;
        nn/=10;
    }
    for(i=1;i*i<n;i++)
        if(n%i==0)
        {
            if(ok(i))cnt++;
            if(ok(n/i))cnt++;
        }
    if(i*i==n && ok(i))cnt++;
    printf("%d\n",cnt);
    return 0;
}