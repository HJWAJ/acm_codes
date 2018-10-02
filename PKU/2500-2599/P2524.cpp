#include<iostream>
using namespace std;

int set[50005];
int rank[50005];
bool flag[50005];

void Make_Set(int i)
{
    set[i]=i;
    rank[i]=0;
}

int Find_Set(int i)
{
    if(set[i]!=i)set[i]=Find_Set(set[i]);
    return set[i];
}

void Union(int i,int j)
{
    i=Find_Set(i);
    j=Find_Set(j);
    if(i==j)return;
    if(rank[i]>rank[j])set[j]=i;
    else
    {
        if(rank[i]==rank[j])rank[j]++;   
        set[i]=j;
    }
}

int main()
{
    int n,m,i,a,b,sum,count=0;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d",&n,&m) &&(n || m))
    {
        memset(flag,0,sizeof(flag));
        count++;
        for(i=0;i<=n;i++)Make_Set(i);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            Union(a,b);
        }
        sum=0;
        for(i=1;i<=n;i++)
        {
            a=Find_Set(i);
            if(!flag[a])
            {
                sum++;
                flag[a]=true;
            }
        }
        printf("Case %d: %d\n",count,sum);
    }
    
    system("pause");
    return 0;
}

 
