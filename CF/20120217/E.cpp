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
#define N 200000
int n,m,c;
struct node{
    double Max,Lmax,Rmax;
}tree[N<<2];
double s[N];
int d[N];

void PushUp(int l,int r,int id){
    int mid=(l+r)>>1;
    tree[id].Max=max(max(tree[id<<1].Max,tree[id<<1|1].Max),tree[id<<1].Rmax+tree[id<<1|1].Lmax);
    tree[id].Lmax=max(tree[id<<1].Lmax,s[mid]-s[l-1]+tree[id<<1|1].Lmax);
    tree[id].Rmax=max(tree[id<<1|1].Rmax,tree[id<<1].Rmax+s[r]-s[mid]);
}

void Build(int l,int r,int id){
    if(l==r){
        tree[id].Max=tree[id].Lmax=tree[id].Rmax=s[l]-s[l-1];
        return;
    }
    int mid=(l+r)>>1;
    Build(l,mid,id<<1);
    Build(mid+1,r,id<<1|1);
    PushUp(l,r,id);
}

node Query(int l,int r,int id,int a,int b){
    if(a<=l&&b>=r) return tree[id];
     int mid=(l+r)>>1;
     if(b<=mid)  return Query(l,mid,id<<1,a,b);
     if(a>mid)   return Query(mid+1,r,id<<1|1,a,b);
     node ans,ans1,ans2;
     ans1=Query(l,mid,id<<1,a,mid);
     ans2=Query(mid+1,r,id<<1|1,mid+1,b);
     ans.Max=max(max(ans1.Max,ans2.Max),ans1.Rmax+ans2.Lmax);
     ans.Lmax=max(ans1.Lmax,s[mid]-s[a-1]+ans2.Lmax);
     ans.Rmax=max(ans2.Rmax,ans1.Rmax+s[b]-s[mid]);
     return ans;
}
int main(){

    int i,j;
    scanf("%d%d%d",&n,&m,&c);
    scanf("%d",&d[0]);
    s[0]=0;
    for(i=1;i<n;i++)
    {
        scanf("%d",d+i);
        s[i]=(d[i]-d[i-1])*0.5;
    }
    for(i=1;i<n;i++)
    {
        scanf("%d",&j);
        s[i]=s[i-1]+s[i]-j/100.0*c;
    }
    Build(1,n-1,1);
    double total=0;
    int a,b;
    node ret;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        ret=Query(1,n-1,1,a,b-1);
        if(ret.Max>0) total+=ret.Max;
    }
    printf("%.9lf\n",total);
    return 0;
}
