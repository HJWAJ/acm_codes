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
    int i,j,k;
    for(i=1;i<=333;i++)
        for(j=i+1;j<=500;j++)
        {
            k=1000-i-j;
            if(i*i+j*j==k*k)
            {
                printf("%d\n",i*j*k);
                return 0;
            }
        }
    return 0;
}
