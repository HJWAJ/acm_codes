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
int main()
{
    int i,j,tmp,sq;
    prime_table();
    for(i=9;;i+=2)
        if(bo[i])
        {
            j=0;
            while(prime[j]<i)
            {
                tmp=i-prime[j];
                tmp/=2;
                sq=(int)sqrt(tmp*1.0);
                if(sq*sq==tmp)break;
                j++;
            }
            if(prime[j]>i)
            {
                printf("%d\n",i);
                break;
            }
        }
    return 0;
}
