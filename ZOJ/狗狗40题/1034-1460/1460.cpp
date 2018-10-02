#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
using namespace std;
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point
{
    double x,y;
    point(int xx,int yy)
    {
        x=xx;
        y=yy;
    }
    point(){}
    bool operator < (const point b) const
    {
        return x < b.x-eps || (fabs(x-b.x)<eps && y<b.y-eps);
    }
    bool operator == (const point b) const
    {
        return fabs(x-b.x)<eps && fabs(y-b.y)<eps;
    }
};
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int opposite_side(point p1,point p2,point l1,point l2){
	return xmult(l1,p1,l2)*xmult(l1,p2,l2)<-eps;
}
int intersect_ex(point u1,point u2,point v1,point v2){
	return opposite_side(u1,u2,v1,v2)&&opposite_side(v1,v2,u1,u2);
}
int parallel(point u1,point u2,point v1,point v2){
	return zero((u1.x-u2.x)*(v1.y-v2.y)-(v1.x-v2.x)*(u1.y-u2.y));
}
point intersection(point u1,point u2,point v1,point v2){
	point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
			/((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;
	return ret;
}
point pnt[105];
bool bo[105];
set<point> st;
int main()
{
    int n,cnt,i,j;
    point pt,apnt[8]={point(0,0),point(0,1000),point(0,1000),point(1000,1000),point(1000,1000),point(1000,0),point(1000,0),point(0,0)};
    while(scanf("%d",&n) && n)
    {
        memset(bo,0,sizeof(bo));
        cnt=1;
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&pnt[i*2].x,&pnt[i*2].y,&pnt[i*2+1].x,&pnt[i*2+1].y);
            //if(pnt[i*2].x==pnt[i*2+1].x && pnt[i*2].y==pnt[i*2+1].y)
            //{
            //    bo[i]=1;
            //    goto label;
            //}
            for(j=0;j<4;j++)
                if((apnt[j*2].x==pnt[i*2].x && apnt[j*2].y==pnt[i*2].y && apnt[j*2+1].x==pnt[i*2+1].x && apnt[j*2+1].y==pnt[i*2+1].y)
                || (apnt[j*2].x==pnt[i*2+1].x && apnt[j*2].y==pnt[i*2+1].y && apnt[j*2+1].x==pnt[i*2].x && apnt[j*2+1].y==pnt[i*2].y))
                {
                    bo[i]=1;
                    goto label;
                }
            for(j=0;j<i;j++)
                if((pnt[j*2].x==pnt[i*2].x && pnt[j*2].y==pnt[i*2].y && pnt[j*2+1].x==pnt[i*2+1].x && pnt[j*2+1].y==pnt[i*2+1].y)
                || (pnt[j*2].x==pnt[i*2+1].x && pnt[j*2].y==pnt[i*2+1].y && pnt[j*2+1].x==pnt[i*2].x && pnt[j*2+1].y==pnt[i*2].y))
                {
                    bo[i]=1;
                    goto label;
                }
            st.clear();
            if(!bo[i])
            for(j=0;j<i;j++)
            {
                if(!bo[j] && intersect_ex(pnt[j*2],pnt[j*2+1],pnt[i*2],pnt[i*2+1]) && !parallel(pnt[j*2],pnt[j*2+1],pnt[i*2],pnt[i*2+1]))
                {
                    pt=intersection(pnt[j*2],pnt[j*2+1],pnt[i*2],pnt[i*2+1]);
                    st.insert(pt);
                }
            }
            //cout<<endl;
            cnt+=st.size()+1;
            label:;
            //cout<<cnt<<endl;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
