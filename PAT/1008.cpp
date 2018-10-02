#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n,sum=0,f=0,to;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&to);
        if(f>to)sum+=4*(f-to);
        else sum+=6*(to-f);
        f=to;
        sum+=5;
    }
    printf("%d\n",sum);
    return 0;
}
