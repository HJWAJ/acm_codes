#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAXN 50005

struct Point
{
    int x, y;
    bool operator < (const Point& _P) const
    {
        return y<_P.y||(y==_P.y&&x<_P.x);
    };
}pset[MAXN],ch[MAXN];

int cross(Point a,Point b,Point o)      
{
    return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

void convex_hull(Point *p,Point *ch,int n,int &len)
{
    sort(p, p+n);
    ch[0]=p[0];
    ch[1]=p[1];
    int top=1;
    for(int i=2;i<n;i++)
    {
        while(top>0&&cross(ch[top],p[i],ch[top-1])<=0)
            top--;
        ch[++top]=p[i];
    }
    int tmp=top;
    for(int i=n-2;i>=0;i--)
    {
        while(top>tmp&&cross(ch[top],p[i],ch[top-1])<=0)
            top--;
        ch[++top]=p[i];
    }
    len=top;    
}

int dist2(Point a,Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int rotating_calipers(Point *ch,int n)
{
    int q=1,ans=0;
    ch[n]=ch[0];
    for(int p=0;p<n;p++)
    {
        while(cross(ch[p+1],ch[q+1],ch[p])>cross(ch[p+1],ch[q],ch[p]))
            q=(q+1)%n;
        ans=max(ans,max(dist2(ch[p],ch[q]),dist2(ch[p+1],ch[q+1])));            
    }
    return ans; 
}

int main()
{
    int n, len;
    while(scanf("%d", &n)!=EOF)
    {
        for(int i = 0;i < n;i++)
        {
            scanf("%d %d",&pset[i].x,&pset[i].y);
        }
        convex_hull(pset,ch,n,len);
        printf("%d\n",rotating_calipers(ch,len));
    }
    return 0;
}