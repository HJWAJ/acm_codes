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
#include<ctime>
using namespace std;
struct point
{
    int x,y;
}pnt[3005];
int cmp(const void *p,const void *q)
{
    point *a=(point *)p;
    point *b=(point *)q;
    if(a->x!=b->x)return a->x - b->x;
    return a->y - b->y;

}
int main()
{
    int n,i,j,num=0;
    point p;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&pnt[i].x,&pnt[i].y);
    }
    qsort(pnt,n,sizeof(pnt[0]),cmp);
    for(i=0;i<n;i++)
        for(j=0;j<i;j++)
            if(((pnt[i].x+pnt[j].x)&1)==0 && ((pnt[i].y+pnt[j].y)&1)==0)
            {
                p.x=(pnt[i].x+pnt[j].x)/2;
                p.y=(pnt[i].y+pnt[j].y)/2;
                if(bsearch((void *)&p,(void *)pnt,n,sizeof(pnt[0]),cmp))num++;
            }
    printf("%d\n",num);
    return 0;
}
