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
    int n,a,b,i,cnt=0,num;
    scanf("%d%d%d",&n,&a,&b);
    for(i=a;i<n;i++)
    {
        num=n-i-1;
        if(num<=b)cnt++;
    }
    printf("%d\n",cnt);
	return 0;
}
