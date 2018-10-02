#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
using namespace std;
int main()
{
    int n,a,b,c,cnt=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a+b+c>1)cnt++;
    }
    printf("%d\n",cnt);
	return 0;
}
