#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int a[100005];
int ans[50005][3],ansnum=0;
struct nod
{
    int n,num;
}node[100005];
int flag=0;
int cmp(const void *p,const void *q)
{
    nod *a=(nod *)p;
    nod *b=(nod *)q;
    return b->num - a->num;
}
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    memset(node,0,sizeof(node));
    node[0].n=a[0];
    node[0].num=1;
    for(i=1;i<n;i++)
    {
        if(a[i]==node[flag].n)node[flag].num++;
        else
        {
            flag++;
            node[flag].n=a[i];
            node[flag].num=1;
        }
    }
    flag++;
    qsort(node,flag,sizeof(node[0]),cmp);
    if(flag<3)
    {
        puts("0");
        return 0;
    }
    int aa=node[0].num,bb=node[1].num,cc=node[2].num;
    for(i=0;i<aa;i++)ans[i][0]=node[0].n;
    for(i=0;i<bb;i++)ans[i][1]=node[1].n;
    for(i=0;i<cc;i++)ans[i][2]=node[2].n;
    for(i=flag-1;i>=3;i--)
    {
        if(aa<=bb && aa<=cc)
        {
            for(j=0;j<node[i].num;j++)ans[aa+j][0]=node[i].n;
            aa+=node[i].num;
        }
        else if(bb<=aa && bb<=cc)
        {
            for(j=0;j<node[i].num;j++)ans[bb+j][1]=node[i].n;
            bb+=node[i].num;
        }
        else if(cc<=bb && cc<=aa)
        {
            for(j=0;j<node[i].num;j++)ans[cc+j][2]=node[i].n;
            cc+=node[i].num;
        }
    }
    ansnum=aa;
    if(ansnum>bb)ansnum=bb;
    if(ansnum>cc)ansnum=cc;
    printf("%d\n",ansnum);
    for(i=0;i<ansnum;i++)
    {
        sort(ans[i],ans[i]+3);
        printf("%d %d %d\n",ans[i][2],ans[i][1],ans[i][0]);
    }
    return 0;
}
