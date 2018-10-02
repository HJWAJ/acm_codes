//效率低。要提高效率的话，可以先二分边界确定到接近10^6，再进行判断是否素数 

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
int prime[200000];
long long sum[200000];
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
    int n,i,j;
    long long tmp;
    n=prime_table();//n=78498
    sum[0]=0;
    for(i=1;i<=n;i++)sum[i]=sum[i-1]+prime[i-1];
    for(i=n;i>0;i--)
        for(j=0;j+i<=n;j++)
        {
            tmp=sum[i+j]-sum[j];
            //cout<<i<<' '<<j<<' '<<tmp<<endl;
            if(tmp<1000000 && !bo[tmp])
            {
                printf("%d\n",tmp);
                return 0;
            }
        }
    return 0;
}
