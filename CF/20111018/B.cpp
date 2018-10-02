#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k,a[1005],i;
    scanf("%d%d",&n,&k);
    k--;
    for(i=0;i<n;i++)scanf("%d",a+i);
    while(1)
    {
        if(!a[k])
        {
            k++;
            if(k==n)k=0;
        }
        else break;
    }
    printf("%d\n",k+1);
	return 0;
}
