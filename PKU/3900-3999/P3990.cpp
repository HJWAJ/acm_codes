#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
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
    int n,i,j;
    double dis;
    point p[4],res[4],pp;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y,&p[3].x,&p[3].y) && !(p[0].x==-1 && p[1].x==-1 && p[2].x==-1 && p[3].x==-1 && p[0].y==-1 && p[1].y==-1 && p[2].y==-1 && p[3].y==-1))
    {
        if(p[0]==p[1] && p[1]==p[2] && p[2]==p[3])pp=p[0];
        else if(p[0]==p[1] && p[1]==p[2])pp=p[0];
        else if(p[0]==p[1] && p[1]==p[3])pp=p[0];
        else if(p[0]==p[2] && p[3]==p[2])pp=p[0];
        else if(p[3]==p[1] && p[1]==p[2])pp=p[1];
        else if( (p[0]==p[1] && p[2]==p[3])
                || (p[0]==p[2] && p[1]==p[3])
                || (p[0]==p[3] && p[1]==p[2]) )pp=p[0];
        else if(p[0]==p[1] || p[0]==p[2] || p[0]==p[3])pp=p[0];
        else if(p[1]==p[2] || p[3]==p[1])pp=p[1];
        else if(p[2]==p[3])pp=p[2];
        else
        {
            n=graham(p,4,res);
            if(n==4)
            {
                dis=dist(res[0],res[2])+dist(res[1],res[3]);
                printf("%.4lf\n",dis);
                continue;
            }
            else
            {
                for(i=0;i<4;i++)
                {
                    for(j=0;j<n;j++)
                        if(res[j]==p[i])break;
                    if(j==n)
                    {
                        pp=p[i];
                        break;
                    }
                }
            }
        }
        dis=0;
        for(i=0;i<4;i++)dis+=dist(pp,p[i]);
        printf("%.4lf\n",dis);
    }
    return 0;
}
