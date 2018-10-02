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
    int n,k,m,i,ans;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(m=1;;m++)
        {
            ans=0;
            for(i=2;i<=n;i++)ans=(ans+m)%i;
            if(ans+1==k)
            {
                printf("%d\n",m);
                break;
            }
        }
    }
    return 0;
}
