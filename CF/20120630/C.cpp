#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n,i;
    scanf("%d",&n);
    if(n==2)
    {
        puts("3");
        return 0;
    }
    if(n==3)
    {
        puts("5");
        return 0;
    }
    if(n%4==0 || n%4==1)
    {
        for(i=1;;i+=2)
        {
            if((i*i+1)/2>=n)
            {
                printf("%d\n",i);
                return 0;
            }
        }
    }
    else
    {
        for(i=1;;i+=2)
        {
            if((i*i+1)/2>=n)
            {
                printf("%d\n",i);
                return 0;
            }
        }
    }
    return 0;
}
