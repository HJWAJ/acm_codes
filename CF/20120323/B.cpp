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
#define eps (1e-8)
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
struct point
{
    double x,y;
};
double xmult(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int inside_convex_v2(point q,int n,point* p)
{
	int i,s[3]={1,1,1};
	for (i=0;i<n&&s[0]&&s[1]|s[2];i++)
		s[_sign(xmult(p[(i+1)%n],q,p[i]))]=0;
	return s[0]&&s[1]|s[2];
}
bool mult(point sp, point ep, point op)
{
    return (sp.x - op.x) * (ep.y - op.y) >= (ep.x - op.x) * (sp.y - op.y);
}
bool operator < (const point &l, const point &r)
{
    return l.y < r.y || (l.y == r.y && l.x < r.x);
}
int graham(point pnt[], int n, point res[])
{
    int i, len, top = 1;
    sort(pnt, pnt + n);
    if (n == 0) return 0; res[0] = pnt[0];
    if (n == 1) return 1; res[1] = pnt[1];
    if (n == 2) return 2; res[2] = pnt[2];
    for (i = 2; i < n; i++)
    {
        while (top && mult(pnt[i], res[top], res[top-1]))
        top--;
        res[++top] = pnt[i];
    }
    len = top; res[++top] = pnt[n - 2];
    for (i = n - 3; i >= 0; i--)
    {
        while (top!=len && mult(pnt[i], res[top], res[top-1])) top--;
        res[++top] = pnt[i];
    }
    return top;
}
point p[100005],pnt[100005],ans[100005];
int main()
{
    int m,n,i,flag=1;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%lf%lf",&p[i].x,&p[i].y);
    scanf("%d",&m);
    for(i=0;i<m;i++)scanf("%lf%lf",&pnt[i].x,&pnt[i].y);
    m=graham(pnt,m,ans);
    for(i=0;i<m;i++)
    {
        flag=inside_convex_v2(ans[i],n,p);
        if(!flag)break;
    }
    if(flag)puts("YES");
    else puts("NO");
    return 0;
}
