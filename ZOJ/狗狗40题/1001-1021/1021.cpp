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
#include<ctime>
using namespace std;
struct nod
{
    int x,y,height;
}node[25];
struct nod2
{
    int l,y,r;
}node2[55];
bool use[25],used;
int stknow[25],stknum[25];
int top;
int main()
{
    int t,n,m,now,i,j,k,target,targetheight,overflow,nowtime,heights;
    scanf("%d",&t);
    while(t--)
    {
        top=0;
        memset(use,0,sizeof(use));
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d%d%d",&node[i].x,&node[i].y,&node[i].height);
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&node2[i].l,&node2[i].y,&node2[i].r);
            node2[i].r+=node2[i].l;
            node2[i].l--;
        }
        scanf("%d%d",&target,&targetheight);
        target--;
        if(targetheight<=node[target].y || targetheight>node[target].y+node[target].height)
        {
            puts("No Solution");
            continue;
        }
        now=0;
        nowtime=1;
        overflow=node[0].y;
        heights=node[0].y+node[0].height;
        use[0]=1;
        while(1)
        {
            used=0;
            for(i=0;i<m;i++)
            {
                if(node2[i].y==heights)
                {
                    for(j=0;j<n;j++)
                        if(use[j])
                        {
                            for(k=0;k<n;k++)
                                if((node2[i].l==node[j].x && node2[i].r==node[k].x) || (node2[i].r==node[j].x && node2[i].l==node[k].x))
                                {
                                    if(!use[k])
                                    {
                                        stknow[top]=nowtime;
                                        stknum[top]=j;
                                        top++;
                                        heights=node[k].y+node[k].height;
                                        if(node[k].y>overflow)overflow=node[k].y;
                                        nowtime=1;
                                        use[k]=1;
                                        used=1;
                                    }
                                    else
                                    {
                                        if(top && (stknum[top-1]==j || stknum[top-1]==k))
                                        {
                                            nowtime+=stknow[top-1];
                                            top--;
                                        }
                                    }
                                    break;
                                }
                            if(k<n)break;
                        }
                    break;
                }
            }
            if(used)continue;
            if(heights <= overflow || targetheight <= overflow)
            {
                puts("No Solution");
                goto end;
            }
            if(heights <= targetheight && use[target])
            {
                printf("%d\n",now);
                goto end;
            }
            heights--;
            now+=nowtime;
        }
        end:;
    }
    return 0;
}
