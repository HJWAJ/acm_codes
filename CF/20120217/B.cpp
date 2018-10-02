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
#include<sstream>
using namespace std;
struct node
{
    int n;
    char name[105];
    int a,b,c;
    int num;
}frd[105];
char s[105];
bool check1(char s[])
{
    if(s[0]==s[1] && s[1]==s[3] && s[3]==s[4] && s[4]==s[6] && s[6]==s[7])return 1;
    return 0;
}
bool check2(char s[])
{
    if(s[0]>s[1] && s[1]>s[3] && s[3]>s[4] && s[4]>s[6] && s[6]>s[7])return 1;
    return 0;
}
int cmp1(const void *p,const void *q)
{
    node *a=(node *)p;
    node *b=(node *)q;
    if(b->a != a->a)return b->a - a->a;
    return a->num - b->num;
}
int cmp2(const void *p,const void *q)
{
    node *a=(node *)p;
    node *b=(node *)q;
    if(b->b != a->b)return b->b - a->b;
    return a->num - b->num;
}
int cmp3(const void *p,const void *q)
{
    node *a=(node *)p;
    node *b=(node *)q;
    if(b->c != a->c)return b->c - a->c;
    return a->num - b->num;
}
int main()
{
    int n,i,j,val;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%s",&frd[i].n,frd[i].name);
        frd[i].num=i;
        frd[i].a=frd[i].b=frd[i].c=0;
        for(j=0;j<frd[i].n;j++)
        {
            scanf("%s",s);
            if(check1(s))frd[i].a++;
            else if(check2(s))frd[i].b++;
            else frd[i].c++;
        }
    }
    qsort(frd,n,sizeof(frd[0]),cmp1);
    printf("If you want to call a taxi, you should call: %s",frd[0].name);
    val=frd[0].a;
    i=1;
    while(frd[i].a==val && i<n)
    {
        printf(", %s",frd[i].name);
        i++;
    }
    puts(".");
    qsort(frd,n,sizeof(frd[0]),cmp2);
    printf("If you want to order a pizza, you should call: %s",frd[0].name);
    val=frd[0].b;
    i=1;
    while(frd[i].b==val && i<n)
    {
        printf(", %s",frd[i].name);
        i++;
    }
    puts(".");
    qsort(frd,n,sizeof(frd[0]),cmp3);
    printf("If you want to go to a cafe with a wonderful girl, you should call: %s",frd[0].name);
    val=frd[0].c;
    i=1;
    while(frd[i].c==val && i<n)
    {
        printf(", %s",frd[i].name);
        i++;
    }
    puts(".");
    return 0;
}
