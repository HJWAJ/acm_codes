#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int i,j,cnt=0;
    for(i=5;i<=12000;i++)
        for(j=i/3;j<=i/2+1;j++)
            if(gcd(i,j)==1 && j*3>i && j*2<i)cnt++;
    printf("%d\n",cnt);
    return 0;
}
