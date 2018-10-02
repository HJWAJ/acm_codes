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
int x[205],y[205];
int main()
{
    int n,i,j,cnt,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d%d",x+i,y+i);
    for(i=0;i<n;i++)
    {
        cnt=0;
        for(j=0;j<n;j++)
            if(x[i]==x[j] && y[i]<y[j])
            {
                cnt++;
                break;
            }
        for(j=0;j<n;j++)
            if(x[i]==x[j] && y[i]>y[j])
            {
                cnt++;
                break;
            }
        for(j=0;j<n;j++)
            if(x[i]<x[j] && y[i]==y[j])
            {
                cnt++;
                break;
            }
        for(j=0;j<n;j++)
            if(x[i]>x[j] && y[i]==y[j])
            {
                cnt++;
                break;
            }
        if(cnt==4)ans++;
    }
    printf("%d\n",ans);
    return 0;
}
