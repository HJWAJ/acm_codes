#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
#include<stack>
#include<sstream>
using namespace std;
int main()
{
    __int64 n,k;
    scanf("%I64d%I64d",&n,&k);
    if(n&1)
    {
        if(k>n/2+1)
        {
            k-=n/2+1;
            k*=2;
        }
        else
        {
            k*=2;
            k--;
        }
    }
    else
    {
        if(k>n/2)
        {
            k-=n/2;
            k*=2;
        }
        else
        {
            k*=2;
            k--;
        }
    }
    printf("%I64d\n",k);
    return 0;
}
