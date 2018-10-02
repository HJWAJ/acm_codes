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
#include<sstream>
using namespace std;
int main()
{
    int n,k,l,c,d,p,nl,np,a,b,cc;
    scanf("%d%d%d%d%d%d%d%d",&n,&k,&l,&c,&d,&p,&nl,&np);
    a=k*l/(n*nl);
    b=c*d/n;
    cc=p/(n*np);
    printf("%d\n",min(a,min(b,cc)));
    return 0;
}
