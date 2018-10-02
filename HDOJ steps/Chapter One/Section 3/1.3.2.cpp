#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct data
{
    char name[20];
    char start[10];
    char end[10];
}node[200005];
int cmp1(const void *p,const void *q)
{
    data* a=(data *)p;
    data* b=(data *)q;
    return strcmp(a->start,b->start);
}
int cmp2(const void *p,const void *q)
{
    data* a=(data *)p;
    data* b=(data *)q;
    return strcmp(b->end,a->end);
}
int main()
{
    int t,n,i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%s%s%s",node[i].name,node[i].start,node[i].end);
        qsort(node,n,sizeof(node[0]),cmp1);
        printf("%s ",node[0].name);
        qsort(node,n,sizeof(node[0]),cmp2);
        printf("%s\n",node[0].name);
    }
    return 0;
}
