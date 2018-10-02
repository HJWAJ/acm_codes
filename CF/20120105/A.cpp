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
const double pi=acos(-1.0);
int main()
{
    int n,R,r;
    scanf("%d%d%d",&n,&R,&r);
    if(R<r)
    {
        puts("NO");
        return 0;
    }
    if(r==R)
    {
        if(n==1)puts("YES");
        else puts("NO");
        return 0;
    }
    if(n==1)
    {
        puts("YES");
        return 0;
    }
    if(n==2)
    {
        if(R>=r*2)puts("YES");
        else puts("NO");
        return 0;
    }
    double ang=pi/n;
    double len=sin(ang)*(R-r);
    //cout<<len<<endl;
    if(len>=r)puts("YES");
    else puts("NO");
    return 0;
}
