#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    __int64 n,x,y,i;
    scanf("%I64d%I64d%I64d",&n,&x,&y);
    if(n>y)puts("-1");
    else if(n-1+(y-n+1)*(y-n+1)>=x)
    {
        for(i=0;i<n-1;i++)printf("1 ");
        printf("%I64d\n",y-n+1);
    }
    else puts("-1");
    return 0;
}
