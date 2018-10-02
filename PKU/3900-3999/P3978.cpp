#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<fstream>
using namespace std;
int prime[50000];
bool bo[100001];
int prime_table()
{
    memset(bo,0,sizeof(bo));
    bo[0]=1;
    bo[1]=1;
    int i,flag=0,tmp;
    for(i=2;i<=100000;i++)
        if(bo[i]==0)
        {
            prime[flag++]=i;
            tmp=i;
            for(;tmp+i<=100000;)
            {
                tmp+=i;
                bo[tmp]=1;
            }
        }
    return flag;
}
int main()
{
    int l,u,i,flag=prime_table(),num;
    while(scanf("%d%d",&l,&u) && !(l==-1 && u==-1))
    {
        for(i=0;i<flag;i++)
            if(prime[i]>=l)break;
        num=i;
        for(;i<flag;i++)
            if(prime[i]>u)break;
        printf("%d\n",i-num);
    }
    return 0;
}
