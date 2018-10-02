//“¿æ…±©¡¶ 

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
    int i;
    double a,b,c;
    for(i=144;;i++)
    {
        a=i*(2*i-1);
        b=(sqrt(1.0+24.0*a)+1.0)/6.0;
        c=(sqrt(1.0+8.0*a)-1.0)/2.0;
        if(ceil(b)==b && ceil(c)==c)
        {
            printf("%lf\n",a);
            return 0;
        }
    }
}
