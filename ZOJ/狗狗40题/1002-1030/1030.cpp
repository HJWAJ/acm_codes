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
struct point
{
    int x,y;
    point(int xx,int yy)
    {
        x=xx;
        y=yy;
    }
    point(){}
};
point pnt[205];
int g[205][15];
bool bo[205];
bool used[205][205];
int cir[205];
int start,cirlen,n;
double atan2(point a,point b)
{
    return atan2((double)(a.x*b.y-b.x*a.y),(double)(a.x*b.x+b.y*a.y));
}
bool iscir(int a,int b)
{
    int i,j,next=-1;
    double theta,tmp;
    point p1,p2;
    cir[cirlen++]=b;
    if(used[a][b])return 0;
    if(bo[b])return 0;
    bo[b]=1;
    used[a][b]=1;
    if(b==start)return 1;
    p1.x=pnt[b].x-pnt[a].x;
    p1.y=pnt[b].y-pnt[a].y;
    theta=1000;
    for(i=1;i<=g[b][0];i++)
        if(g[b][i]!=a)
        {
            j=g[b][i];
            p2.x=pnt[j].x-pnt[b].x;
            p2.y=pnt[j].y-pnt[b].y;
            tmp=atan2(p2,p1);
            if(tmp<theta)
            {
                theta=tmp;
                next=g[b][i];
            }
        }
    if(next==-1)return 0;
    return iscir(b,next);
}
#define _sign(x) ((x)>0?1:((x)<0?2:0))
int xmult(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int inside_convex(point q,int n,point* p)
{
	int i,s[3]={1,1,1};
	for (i=0;i<n&&s[1]|s[2];i++)
		s[_sign(xmult(p[(i+1)%n],q,p[i]))]=0;
	return s[1]|s[2];
}
bool ok(int a)
{
    point p[205];
    int i,j;
    for(i=0;i<cirlen;i++)
    {
        p[i].x=pnt[cir[i]].x;
        p[i].y=pnt[cir[i]].y;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<cirlen;j++)
            if(i==cir[j])
                continue;
        if(inside_convex(pnt[i],cirlen,p))return 0;
    }
    return 1;
}
double area_polygon(int n,point* p)
{
	double s1=0,s2=0;
	int i;
	for (i=0;i<n;i++)
		s1+=p[(i+1)%n].y*p[i].x,s2+=p[(i+1)%n].y*p[(i+2)%n].x;
	return (s1-s2)/2.0;
}
double area()
{
    point p[205];
    int i;
    for(i=0;i<cirlen;i++)
    {
        p[i].x=pnt[cir[i]].x;
        p[i].y=pnt[cir[i]].y;
    }
    return area_polygon(cirlen,p);
}
int main()
{
    int t,i,id,len,cnt,j,k;
    scanf("%d",&t);
    while(t--)
    {
        memset(used,0,sizeof(used));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&id);
            id--;
            scanf("%d%d",&pnt[id].x,&pnt[id].y);
            scanf("%d",&g[id][0]);
            for(j=1;j<=g[id][0];j++)
            {
                scanf("%d",&g[id][j]);
                g[id][j]--;
            }
        }
        scanf("%d",&len);
        if(len<3)
        {
            puts("0");
            continue;
        }
        cnt=0;
        for(i=0;i<n;i++)
        {
            start=i;
            k=g[i][0];
            for(j=1;j<=k;j++)
            {
                cirlen=0;
                memset(bo,0,sizeof(bo));
                if(iscir(i,g[i][j]))
                {
                    cir[cirlen]=g[i][j];
                    //cout<<area()<<' '<<ok(i)<<endl;
                    if(cirlen==len && !ok(i) && area()>0)cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
