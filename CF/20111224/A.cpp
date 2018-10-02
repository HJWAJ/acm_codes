#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n,a[7],i,j;
    scanf("%d",&n);
    for(i=0;i<7;i++)scanf("%d",a+i);
    j=0;
    while(1)
    {
        n-=a[j];
        if(n<=0)
        {
            printf("%d\n",j+1);
            break;
        }
        j++;
        if(j==7)j=0;
    }

    return 0;
}
