#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;
int main()
{
    __int64 a,b,mod;
    scanf("%I64d%I64d%I64d",&a,&b,&mod);
    if(b>=mod-1)puts("2");
    else puts("1 000000001");
    return 0;
}
