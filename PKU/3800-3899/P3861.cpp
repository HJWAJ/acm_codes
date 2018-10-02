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
int main()
{
    int a[6][6]={0,1,1,2,2,3,
                 1,2,2,4,4,6,
                 1,2,3,5,6,7,
                 2,4,5,6,8,10,
                 2,4,6,8,10,12,
                 3,6,7,10,12,15};
    int m,n;
    while(scanf("%d%d",&m,&n) && (m||n))printf("%d\n",a[m-2][n-2]);
    return 0;
}
