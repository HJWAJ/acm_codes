#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std;
int a[105];
int main()
{
    int n,tmp,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&tmp);
        a[tmp]=i;
    }
    printf("%d",a[1]);
    for(i=2;i<=n;i++)printf(" %d",a[i]);
    puts("");
    return 0;
}
