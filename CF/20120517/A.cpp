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
    int a,b;
    scanf("%d%d",&a,&b);
    if(a==0 && b!=0)puts("Impossible");
    else if(a==0 && b==0)puts("0 0");
    else if(a!=0 && b==0)printf("%d %d\n",a,a);
    else if(a>=b)printf("%d %d\n",a,a+b-1);
    else printf("%d %d\n",b,a+b-1);
	return 0;
}
