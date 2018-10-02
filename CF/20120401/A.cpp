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
    int a,b,bb=0,tmp;
    scanf("%d%d",&a,&b);
    while(b)
    {
        bb*=10;
        tmp=b%10;
        b/=10;
        bb+=tmp;
    }
    a+=bb;
    printf("%d\n",a);
    return 0;
}
