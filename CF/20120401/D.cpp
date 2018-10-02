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
int main()
{
    int n;
    scanf("%d",&n);
    if(n==3)puts("1");
    else if(n==1 || n==4)puts("2");
    else if(n==2)puts("3");
    else puts("1");
    return 0;
}
