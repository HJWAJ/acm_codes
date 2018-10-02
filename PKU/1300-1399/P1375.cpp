#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

const double eps=1e-6;

struct node
{
    double x,y;
}src,temp,r1,r2;

struct inter
{
    double l,r;
}ans[505];//区间 

bool operator <(inter a,inter b)
{
    if(fabs(a.l-b.l)<eps)return a.r<b.r;
    return a.l<b.l;
}

int n;
double r;

node rotate(node a,double ang)//将向量旋转角度 
{
    node res;
    res.x=a.x*cos(ang)-a.y*sin(ang);
    res.y=a.x*sin(ang)+a.y*cos(ang);
    return res;
}

void tangent()//求出圆的切线的两个切点坐标 
{
    double dist=sqrt((src.x-temp.x)*(src.x-temp.x)+(src.y-temp.y)*(src.y-temp.y));
    double ang=acos(r/dist);
    node line,unit;
    line.x=src.x-temp.x;
    line.y=src.y-temp.y;
    unit.x=line.x/sqrt(line.x*line.x+line.y*line.y)*r;
    unit.y=line.y/sqrt(line.x*line.x+line.y*line.y)*r;
    r1=rotate(unit,-ang);//圆与切线的交点1 
    r2=rotate(unit,ang);//圆与切线的交点2 
    r1.x+=temp.x;
    r1.y+=temp.y;
    r2.x+=temp.x;
    r2.y+=temp.y;
}

int main()
{
    while(scanf("%d",&n),n)
    {
        scanf("%lf%lf",&src.x,&src.y);
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf%lf",&temp.x,&temp.y,&r);
            tangent();
            double x1=(r1.y*src.x-r1.x*src.y)/(r1.y-src.y);//切线与底线的两个交点 
            double x2=(r2.y*src.x-r2.x*src.y)/(r2.y-src.y);
            if(x1>x2)swap(x1,x2);
            ans[i].l=x1;
            ans[i].r=x2;
        }
        sort(ans,ans+n);
        printf("%.2lf",ans[0].l);
        double fin=ans[0].r;
        for(int i=1;i<n;i++)
        {
            if(fabs(fin-ans[i].l)>=eps&&ans[i].l>fin)
                printf(" %.2lf\n%.2lf",fin,ans[i].l);
            if(fin<ans[i].r)fin=ans[i].r;    
        }
        printf(" %.2lf\n",fin);
        printf("\n");
    }
    
    //system("pause");
    return 0;
}
