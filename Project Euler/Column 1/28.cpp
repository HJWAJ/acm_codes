//formula by OEIS.org

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    long long n=500;
    printf("%lld\n",n*n*10+(n*n*n*16+n*26)/3+1);
    return 0;
}
