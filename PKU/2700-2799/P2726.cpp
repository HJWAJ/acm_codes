#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct node
{
    int a,b;
}nod[10005];

bool operator <(const node &a,const node &b)
{
    if(a.a==b.a)return a.b<b.b;
    return a.a<b.a;     
}

int main()
{
    int n,i,cnt,min;
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)scanf("%d%d",&nod[i].a,&nod[i].b);
        sort(nod,nod+n);
        cnt=0;min=99999999;
        for(i=0;i<n;i++)
            if(nod[i].b<min)
            {
                min=nod[i].b;
                cnt++;                
            }
        printf("%d\n",cnt);
    }
    
    return 0;
}
