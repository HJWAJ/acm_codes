#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const double PI=acos(-1.0);
struct point
{
    double x, y;
};
double dist(point p1,point p2)
{
    return sqrt( (p1.x-p2.x) * (p1.x-p2.x) + (p1.y-p2.y) * (p1.y-p2.y) );
}
bool mult(point sp, point ep, point op)
{
    return (sp.x-op.x) * (ep.y-op.y) >= (ep.x-op.x) * (sp.y-op.y);
}
bool operator <(const point &l, const point &r)
{
    return l.y < r.y || (l.y == r.y && l.x < r.x);
}
bool operator ==(const point &l,const point &r)
{
    return l.y == r.y && l.x == r.x;
}
int graham(point pnt[],int n, point res[])
{
    int i,len,top=1;
    sort(pnt,pnt+n);
    if(n==0)return 0; res[0]=pnt[0];
    if(n==1)return 1; res[1]=pnt[1];
    if(n==2)return 2; res[2]=pnt[2];
    for(i=2;i<n;i++)
    {
        while(top && mult(pnt[i],res[top],res[top-1]))top--;
        res[++top]=pnt[i];
    }
    len=top; res[++top]=pnt[n-2];
    for(i=n-3;i>=0;i--)
    {
        while(top!=len && mult(pnt[i],res[top],res[top-1]))top--;
        res[++top]=pnt[i];
    }
    return top;
}
int main()
{
    int n,i,num;
    double dis=0,r,s;
    point p[1005],res[1005];
    scanf("%d%lf",&n,&r);
    for(i=0;i<n;i++)scanf("%lf%lf",&p[i].x,&p[i].y);
    num=graham(p,n,res);
    for(i=0;i<num-1;i++)dis+=dist(res[i],res[i+1]);
    dis+=dist(res[num-1],res[0]);
    s=dis+2*PI*r;
    printf("%.0lf\n",s);
    return 0;
}
