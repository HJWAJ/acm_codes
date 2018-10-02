#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int prime[300000];
bool bo[3000001];
int prime_table()
{
    int i,j,flag=0;
    memset(bo,0,sizeof(bo));
    bo[0]=bo[1]=1;
    for(i=2;i<=2000;i++)
        if(!bo[i])
        {
            j=i*i;
            for(;j<=3000000;j+=i)bo[j]=1;
        }
    for(i=0;i<=3000000;i++)
        if(!bo[i])prime[flag++]=i;
    return flag;
}
int main()
{
    int i,j,n,max=-1,maxp;
    prime_table();
    for(i=-999;i<1000;i++)
        for(j=-999;j<1000;j++)
        {
            n=0;
            while(n*n+i*n+j>1 && (!bo[n*n+i*n+j]))n++;
            if(n>max)
            {
                max=n;
                maxp=i*j;
            }
        }
    printf("%d\n",maxp);
    return 0;
}
