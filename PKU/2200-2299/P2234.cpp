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
    int n,a,sum;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        while(n--)
        {
            scanf("%d",&a);
            sum^=a;
        }
        if(sum==0)puts("No");
        else puts("Yes");
    }
	return 0;
}
