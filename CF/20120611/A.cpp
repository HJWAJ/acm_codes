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
#include<windows.h>
using namespace std;
int main()
{
    int a,b,c,t;
    scanf("%d%d%d",&a,&b,&c);
    if((a-b)*c%b==0)t=(a-b)*c/b;
    else t=(a-b)*c/b+1;
    printf("%d\n",t);
    return 0;
}
