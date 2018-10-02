#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    int n=100;
    printf("%d\n",n*n*(n+1)*(n+1)/4-n*(n+1)*(2*n+1)/6);
    return 0;
}
