#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int f[1005];
int main()
{
    int i,num,sum=0;
    f[0]=1;f[1]=2;
    for(i=2;f[i-1]<=4000000;i++)f[i]=f[i-1]+f[i-2];
    num=i;
    for(i=0;i<num;i++)
        if(!(f[i]&1))sum+=f[i];
    printf("%d\n",sum);
    return 0;
}
