#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
int prime[200000];
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
int pow4(int a)
{
    return a*a*a*a;
}
int pow3(int a)
{
    return a*a*a;
}
int pow2(int a)
{
    return a*a;
}
set<long long> ss;
int main()
{
    int i,j,k,s=50000000;
    prime_table();
    for(i=0;;i++)
    {
        if(pow4(prime[i])>s)break;
        for(j=0;;j++)
        {
            if(pow4(prime[i])+pow3(prime[j])>s)break;
            for(k=0;;k++)
            {
                if(pow4(prime[i])+pow3(prime[j])+pow2(prime[k])>s)break;
                ss.insert(pow4(prime[i])+pow3(prime[j])+pow2(prime[k]));
            }
        }
    }
    printf("%d\n",ss.size());
    return 0;
}
