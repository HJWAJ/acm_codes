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
#include<sstream>
using namespace std;
struct node
{
    int val,id;
}a[100005];
int cmp(const void *p,const void *q)
{
    node *a=(node *)p;
    node *b=(node *)q;
    if(a->val==b->val)return a->id - b->id;
    return a->val - b->val;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i].val);
        a[i].id=i;
    }
    qsort(a,n,sizeof(a[0]),cmp);
    if(a[0].val==a[1].val)puts("Still Rozdil");
    else printf("%d\n",a[0].id+1);
    return 0;
}
