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
    int n,k,a[105],i,sum=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)scanf("%d",a+i);
    for(i=0;i<n;i++)
    {
        if(a[i]>=3*k)a[i]-=3*k;
        else a[i]%=k;
    }
    for(i=0;i<n;i++)sum+=a[i];
    printf("%d\n",sum);
	return 0;
}
