#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int a[]={1,2,3,4,5,6,7,8,9};
int main()
{
    int r1,r2,c1,c2,d1,d2,cnt=0;
    scanf("%d%d%d%d%d%d",&r1,&r2,&c1,&c2,&d1,&d2);
    do
    {
        cnt++;
        if(cnt>2000000)
        {
            puts("-1");
            break;
        }
        if(a[0]+a[3]==d1 && a[2]+a[1]==d2 && a[0]+a[1]==r1 && a[2]+a[3]==r2 && a[0]+a[2]==c1 && a[1]+a[3]==c2)
        {
            printf("%d %d\n%d %d\n",a[0],a[1],a[2],a[3]);
            break;
        }
        next_permutation(a,a+9);
    }while(1);
    return 0;
}
