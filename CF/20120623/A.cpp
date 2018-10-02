#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int f[10005];
int main()
{
    int n,i;
    scanf("%d",&n);
    if(n==0)puts("0 0 0");
    else if(n==1)puts("0 0 1");
    else if(n==2)puts("0 1 1");
    else
    {
        f[0]=f[1]=1;
        f[2]=2;
        for(i=2;;i++)
        {
            f[i]=f[i-1]+f[i-2];
            if(f[i]==n)break;
        }
        printf("%d %d %d\n",f[i-3],f[i-2],f[i-2]);
    }
    return 0;
}
