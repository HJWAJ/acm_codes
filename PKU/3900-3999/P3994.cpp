#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
    int n,tt=0;
    while(scanf("%d",&n) && n)
    {
        tt++;
        if(n&1)printf("%d. odd %d\n",tt,n/2);
        else printf("%d. even %d\n",tt,n/2);
    }
    return 0;
}
