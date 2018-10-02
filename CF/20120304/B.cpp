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
#include<ctime>
using namespace std;
int a[15];
int main()
{
    int n,tmp,cnt=0;
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&tmp);
        a[tmp]++;
    }
    cnt+=a[4];
    cnt+=a[3];
    if(a[1]>a[3])a[1]-=a[3];
    else a[1]=0;
    cnt+=a[2]/2;
    a[2]%=2;
    if(a[2])
    {
        cnt++;
        if(a[1]>2)a[1]-=2;
        else a[1]=0;
    }
    cnt+=a[1]/4;
    a[1]%=4;
    if(a[1])cnt++;
    printf("%d\n",cnt);
    return 0;
}
