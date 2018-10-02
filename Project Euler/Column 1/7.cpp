#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int prime[30000];
bool bo[1000001];
int prime_table()
{
    int i,j,flag=0;
    memset(bo,0,sizeof(bo));
    bo[0]=bo[1]=1;
    for(i=2;i<=1000;i++)
        if(!bo[i])
        {
            j=i*i;
            for(;j<=1000000;j+=i)bo[j]=1;
        }
    for(i=0;i<=1000000;i++)
        if(!bo[i])prime[flag++]=i;
    return flag;
}
int main()
{
    prime_table();
    printf("%d\n",prime[10000]);
    return 0;
}
