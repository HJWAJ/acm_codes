#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct stu
{
    int id,point,rank;
}node[1005];
int cmp(const void *p,const void *q)
{
    stu *a=(stu *)p;
    stu *b=(stu *)q;
    return b->point - a->point;
}
int main()
{
    int num,i,n;
    while(scanf("%d",&num)!=EOF)
    {
        i=0;
        while(scanf("%d%d",&node[i].id,&node[i].point) && !(node[i].id==0 && node[i].point==0))i++;
        n=i;
        qsort(node,n,sizeof(node[0]),cmp);
        node[0].rank=1;
        if(node[0].id==num)
        {
            printf("%d\n",node[0].rank);
            continue;
        }
        for(i=1;i<n;i++)
        {
            if(node[i].point==node[i-1].point)node[i].rank=node[i-1].rank;
            else node[i].rank=i+1;
            if(node[i].id==num)
            {
                printf("%d\n",node[i].rank);
                break;
            }
        }
    }
    return 0;
}
