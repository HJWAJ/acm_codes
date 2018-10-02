#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<cmath>
#include<string>
using namespace std;
int cnt[1445];
int main()
{
    int n,i,a,b,m=0;
    memset(cnt,0,sizeof(cnt));
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&a,&b);
        a=a*60+b;
        cnt[a]++;
    }
    for(i=0;i<1440;i++)
        if(cnt[i]>m)
            m=cnt[i];
    printf("%d\n",m);
    return 0;
}
