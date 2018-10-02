#include<iostream>
using namespace std;

struct vec
{
    int x;
    int y;       
}a[50000];

int cmp(const void *p1,const void *p2)
{
    struct vec *a=(vec *)p1;
    struct vec *b=(vec *)p2;
    if(a->x!=b->x)return a->x - b->x;
    return a->y - b->y;   
}

int main()
{
    int n;
    while(scanf("%d",&n) && n!=0)
    {
        int i;
        for(i=0;i<n;i++)scanf("%d%d",&a[i].x,&a[i].y);
        int cnt=1;
        qsort(a,n,sizeof(a[0]),cmp);
        int xx=a[n-1].x;
        int yy=a[n-1].y;
        for(i=n-2;i>=0;i--)
        {
            if(a[i].x!=xx)
                if(a[i].y>yy)
                {
                    yy=a[i].y;
                    xx=a[i].x;
                    cnt++;
                }
        }
        printf("%d\n",cnt);
    }    
    
    system("pause");
    return 0;
}
