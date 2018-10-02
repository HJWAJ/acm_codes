#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct nod
{
    char id[20];
    int time;
}node[100005];
int gettime(int h,int min,int s)
{
    return h*3600+min*60+s;
}
bool cmp(nod a, nod b)
{
    return a.time<b.time;
}
int main()
{
    int n,num=0;
    scanf("%d",&n);
    while(n--)
    {
        char name[20];
        int time,h,min,s;
        scanf("%s %d:%d:%d",name,&h,&min,&s);
        time=gettime(h,min,s);
        strcpy(node[num].id,name);
        node[num++].time=time;
        scanf("%d:%d:%d",&h,&min,&s);
        time=gettime(h,min,s);
        strcpy(node[num].id,name);
        node[num++].time=time;
    }
    sort(node,node+num,cmp);
    printf("%s %s\n",node[0].id,node[num-1].id);
    return 0;
}
