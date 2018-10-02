//暴力了，但总觉得有好方法的 

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
using namespace std;
const double eps=1E-8;
int main()
{
    int i,j;
    double a,b;
    for(i=1;;i++)
        for(j=1;j<=i;j++)
        {
            a=(sqrt(1.0+12.0*(3.0*(i*i+j*j)-i-j))+1.0)/6.0;
            b=(sqrt(1.0+12.0*(3.0*(i*i-j*j)-i+j))+1.0)/6.0;
            if(ceil(a)==a && ceil(b)==b)
            {
                printf("%lf\n",b*(3*b-1)/2);//5482660
                return 0;
            }
		}
}
