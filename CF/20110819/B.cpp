#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<deque>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<fstream>
using namespace std;
struct compu
{
    int speed,ram,hdd,cost,num;
    bool operator <(const compu c)
    {
        if(speed<c.speed && ram<c.ram && hdd<c.hdd)return 1;
        return 0;
    }
}com[105],com2[105];
bool bo[105];
int cmp2(const void *p,const void *q)
{
    compu *a=(compu *)p;
    compu *b=(compu *)q;
    return a->cost - b->cost;
}
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&com[i].speed,&com[i].ram,&com[i].hdd,&com[i].cost);
        com[i].num=i;
    }
    memset(bo,0,sizeof(bo));
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(com[i]<com[j])
            {
                bo[i]=1;
                break;
            }
    j=0;
    for(i=0;i<n;i++)
        if(!bo[i])
        {
            com2[j]=com[i];
            j++;
        }
    n=j;
    qsort(com2,n,sizeof(com2[0]),cmp2);
    //for(i=0;i<n;i++)cout<<com2[0].cost<<' '<<com2[0].num<<endl;
    printf("%d\n",com2[0].num+1);
    return 0;
}
