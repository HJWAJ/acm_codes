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
struct circle
{
    int x,y,r;
}c[4];
bool intersect(circle c1,circle c2)
{
    int d,d1,d2;
    d=(c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y);
    d1=(c1.r-c2.r)*(c1.r-c2.r);
    d2=(c1.r+c2.r)*(c1.r+c2.r);
    if(d>d1 && d<d2)return 1;
    return 0;
}
int main()
{
    scanf("%d%d%d%d",&c[0].x,&c[0].y,&c[0].r,&c[1].r);
    scanf("%d%d%d%d",&c[2].x,&c[2].y,&c[2].r,&c[3].r);
    c[1].x=c[0].x;c[1].y=c[0].y;
    c[3].x=c[2].x;c[3].y=c[2].y;
    int cnt=0;
    if(!intersect(c[0],c[2]) && !intersect(c[0],c[3]))cnt++;
    if(!intersect(c[1],c[2]) && !intersect(c[1],c[3]))cnt++;
    if(!intersect(c[2],c[0]) && !intersect(c[2],c[1]))cnt++;
    if(!intersect(c[3],c[0]) && !intersect(c[3],c[1]))cnt++;
    printf("%d\n",cnt);
    return 0;
}
