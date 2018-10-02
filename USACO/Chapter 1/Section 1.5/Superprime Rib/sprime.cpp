/*
ID: hjw00002
PROG: sprime
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

bool isnPrime(int n)
{
    int i,sq=int(sqrt(double(n)));
    for(i=2;i<=sq;i++)
        if(n%i==0)return 1;
    return 0;
}

void dfs(int num,int k,int n)
{
     if(isnPrime(num))return;
     if(k==n)printf("%d\n",num);
     else
     { 
         dfs(num*10+1,k+1,n);
         dfs(num*10+3,k+1,n);
         dfs(num*10+7,k+1,n);
         dfs(num*10+9,k+1,n);
     }
}

int main()
{
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);
    int n;
    scanf("%d",&n);
    dfs(2,1,n);
    dfs(3,1,n);
    dfs(5,1,n);
    dfs(7,1,n);
    
    //system("pause");
    return 0;
}
