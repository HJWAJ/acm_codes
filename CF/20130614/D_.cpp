#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
#include<stack>
#include<sstream>
using namespace std;
const int dir[4][2]={1,0,0,1,-1,0,0,-1};
struct point
{
    int x,y;
    bool operator < (const point &b) const
    {
        if(x!=b.x)return x<b.x;
        return y<b.y;
    }
};
map<point,int> mymap;
void init(int n)
{
    int i;
    point p,pp[4];
    p.x=p.y=0;
    mymap[p]=n;
    queue<point> que;
    while(!que.empty())que.pop();
    que.push(p);
    while(!que.empty())
    {
        if(mymap[que.front()]>=4)
        {
            for(i=0;i<4;i++)
            {
                pp[i]=que.front();
                pp[i].x+=dir[i][0];
                pp[i].y+=dir[i][1];
                mymap[pp[i]]+=mymap[que.front()]/4;
                que.push(pp[i]);
            }
            mymap[que.front()]%=4;
        }
        que.pop();
        //cout<<que.size()<<endl;
        /*
        for(int i=-5;i<=5;i++)
        {
            for(int j=-5;j<=5;j++)
            {
                point ps;
                ps.x=i;ps.y=j;
                cout<<mymap[ps]<<' ';
            }
            cout<<endl;
        }
        getchar();
        getchar();
        */
    }
}
int main()
{
    int n,t,xx,yy;
    point tmp;
    scanf("%d%d",&n,&t);
    init(n);
    while(t--)
    {
        scanf("%d%d",&xx,&yy);
        tmp.x=xx;
        tmp.y=yy;
        if(mymap.find(tmp)==mymap.end())puts("0");
        else printf("%d\n",mymap[tmp]);
    }
    return 0;
}
