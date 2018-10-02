#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<vector>
using namespace std;
int main()
{
    int n,a[105],i,x,y;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)scanf("%d",a+i);
        scanf("%d%d",&x,&y);
        for(i=0;i<n;i++)
            if(!(a[i]&1))
            {
                puts("Yes");
                break;
            }
        if(i<n)continue;
        if((x^y)&1)puts("No");
        else puts("Yes");
    }
    return 0;
}
