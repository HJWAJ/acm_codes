#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

struct dis
{
    int start,end;
}a[25000];
//bool val[1000001];

int cmp(const void *p1,const void *p2)
{
    dis *a=(dis *)p1;
    dis *b=(dis *)p2;
    if(a->start == b->start)return a->end - b->end;
    return a->start - b->start;    
}

int main()
{
    int m,n,i,flag=0,max,cnt=0,flag0=0;
    scanf("%d%d",&m,&n);
    flag=flag0=cnt=0;
    for(i=0;i<m;i++)scanf("%d%d",&a[i].start,&a[i].end);
    qsort(a,m,sizeof(a[0]),cmp);
    a[m].start=-1;
    for(i=0;i<m;i++)
    {
        if(a[i].start==a[i+1].start)continue;
        if(a[i].start<=flag0+1)
        {
            if(flag<a[i].end)
            {
                flag=a[i].end;
                if(flag==n)
                {cnt++;break;}
                if(i==m-1)cnt++;
            }                       
        }
        else
        {
            if(a[i].start>flag+1)
            {
                printf("-1\n");
                return 0;
            }
            else
            {
                flag0=flag;
                cnt++;
                i--;
            }
        }
    }
    flag0=flag;
    if(flag0>=n)printf("%d\n",cnt);
    else printf("-1\n");
    
    //system("pause");    
    return 0;
}
