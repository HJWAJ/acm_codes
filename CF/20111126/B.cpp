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
int bo[10][2];
int main()
{
    int i,n,a;
    __int64 ans=0;
    memset(bo,0,sizeof(bo));
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        if(a>=0)bo[a][0]++;
        else bo[-a][1]++;
    }
    //cout<<bo[0][0]<<endl;
    ans=(__int64)bo[0][0]*(bo[0][0]-1)/2LL;
    for(i=1;i<=10;i++)ans+=(__int64)bo[i][0]*bo[i][1];
    printf("%I64d\n",ans);
    return 0;
}
