#include<iostream>
using namespace std;
const int N=100001;

struct ANIMAL 
{
    int parent;
    int rank;
    int enemy;
    int food;
};

ANIMAL animal[N];
int n,k;

void initial(int n)
{
    int i;
    for (i=1;i<=n;i++)
    {
        animal[i].parent=i;
        animal[i].rank=0;
        animal[i].enemy=-1;
        animal[i].food=-1;
    }
}

int find_set(int x)
{
    if(x==-1)return -1;
    int p=x;
    while(animal[x].parent!=x)x=animal[x].parent;
    while(animal[p].parent!=x)
    {
        animal[p].parent=x;
        p=animal[p].parent;
    }
    return x;
}

int union_set(int x,int y)
{
    if(x==-1)return y;
    if(y==-1)return x;
    if(animal[x].rank>animal[y].rank)
    {
        animal[y].parent=x;
        return x;
    }
    else
    {
        animal[x].parent = y;
        if(animal[x].rank == animal[y].rank)animal[y].rank++;
        return y;
    }
}

void make_set(int x,int y,int fx,int fy,int ex,int ey)//x->y
{
    int t,v,w;
    t=union_set(fx,y);
    v=union_set(x,ey);
    w=union_set(ex,fy);
    animal[v].enemy=w;
    animal[v].food=t;
    animal[t].enemy=v;
    animal[t].food=w;
    if(w!=-1)
    {
        animal[w].food=v;
        animal[w].enemy=t;
    }
}

int main()
{
         int ans,i,j;
         int d,x,y;
         int fx,fy,ex,ey;
         int t,u,v;
         scanf("%d%d",&n,&k);
         initial(n);
         ans=0;
         for(i=0;i<k;i++)
         {
             scanf("%d%d%d",&d,&x,&y);
             if(x>n || y>n)    // 假话1
             {
                 ans++;
                 continue;
             }
             if(d==2 && x==y)//假话2
             {
                 ans++;
                 continue;
             }
             x=find_set(x);
             y=find_set(y);
             fx=find_set(animal[x].food);
             ex=find_set(animal[x].enemy);
             fy=find_set(animal[y].food);
             ey=find_set(animal[y].enemy);
             if(x==y)
             {
                 if(d==2)ans++;
                 continue;
             }
             if(x==fy)
             {
                 ans++;
                 continue;
             }
             if(y==fx)
             {
                 if(d==1)ans++;
                 continue;
             }
             if(d==1)
             {        //尚未建立关系
                 t=union_set(x,y);
                 u=union_set(fx,fy);
                 v=union_set(ex,ey);
                 animal[t].food=u;
                 animal[t].enemy=v;
                 if(u!=-1)
                 {
                     animal[u].enemy=t;
                     animal[u].food=v;
                 }
                 if(v!=-1)
                 {
                     animal[v].food=t;
                     animal[v].enemy=u;
                 }
             }
             else make_set(x,y,fx,fy,ex,ey);
         }
         printf("%d\n",ans);

         return 0;
}
