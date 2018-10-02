#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int a[105],n,i;
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)scanf("%d",a+i);
        if(n&1)puts("1");
        else
        {
            sort(a,a+n);
            for(i=0;i<n;i+=2)
                if(a[i]!=a[i+1])break;
            if(i!=n)puts("1");
            else puts("0");
        }
    }
	return 0;
}
