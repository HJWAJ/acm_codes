#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
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
int divide(int n,int p[],int a[])
{
    long long int sq=(long long int)(sqrt(double(n)));
    int flag=0,num=0;
    while(1)
    {
        if(n==1)break;
        if(prime[flag]>sq)
        {
            p[num]=n;
            a[num++]=1;
            break;
        }
        if(n%prime[flag]!=0)
        {
            flag++;
            continue;
        }
        p[num]=prime[flag];
        a[num++]=1;
        n/=prime[flag];
        while(n%prime[flag]==0)
        {
            n/=prime[flag];
            a[num-1]++;
        }
        flag++;
    }
    return num;
}
int num[1000005];
int p[105],a[105];
int main()
{
    int i;
    prime_table();
    for(i=644;i<=1000000;i++)num[i]=divide(i,p,a);
    for(i=644;i<=999997;i++)
        if(num[i]==4 && num[i+1]==4 && num[i+2]==4 && num[i+3]==4)
        {
            printf("%d\n",i);
            break;
        }
    return 0;
}
