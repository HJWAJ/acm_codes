#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
bool ok(int m)
{
    int i,j,a,b,cnt=0,tmp;
    double sq;
    for(i=1;i<=m;i++)
        for(j=2;j<=2*i;j++)
        {
            a=i*i;
            b=j*j;
            sq=sqrt(a+b);
            if(sq==floor(sq))
            {
                tmp=min((2*i-j+2),j)/2;
                cnt+=tmp;
            }
        }
    if(cnt>1000000)return 1;
    return 0;
}
int main()
{
    int l=0,r=2000,mid;
    while(l<r-1)
    {
        mid=(l+r)/2;
        if(ok(mid))r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",l);
    return 0;
}
