#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std;
struct point
{
    int x,y;
}pnt[8];
bool bo[8];
bool line(point a,point b,point c)
{
    if( (a.x-b.x)*(a.y-c.y) == (a.y-b.y)*(a.x-c.x) )return 1;
    return 0;
}
int dis(point a,point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
bool is1(int a,int b,int c,int d)
{
    int len[6];
    if( line(pnt[a],pnt[b],pnt[c]) || line(pnt[a],pnt[b],pnt[d]) || line(pnt[a],pnt[d],pnt[c]) || line(pnt[d],pnt[b],pnt[c]) )return 0;
    len[0]=dis(pnt[a],pnt[b]);
    len[1]=dis(pnt[a],pnt[c]);
    len[2]=dis(pnt[a],pnt[d]);
    len[3]=dis(pnt[c],pnt[b]);
    len[4]=dis(pnt[d],pnt[b]);
    len[5]=dis(pnt[c],pnt[d]);
    sort(len,len+6);
    if(len[0]==len[1] && len[2]==len[1] && len[2]==len[3] && len[4]==len[5] && len[4]==2*len[1])return 1;
    return 0;
}
bool is2(int a[])
{
    int len[6];
    if( line(pnt[a[0]],pnt[a[1]],pnt[a[2]]) || line(pnt[a[0]],pnt[a[1]],pnt[a[3]]) || line(pnt[a[0]],pnt[a[2]],pnt[a[3]]) || line(pnt[a[1]],pnt[a[2]],pnt[a[3]]) )return 0;
    len[0]=dis(pnt[a[0]],pnt[a[1]]);
    len[1]=dis(pnt[a[0]],pnt[a[2]]);
    len[2]=dis(pnt[a[0]],pnt[a[3]]);
    len[3]=dis(pnt[a[1]],pnt[a[2]]);
    len[4]=dis(pnt[a[1]],pnt[a[3]]);
    len[5]=dis(pnt[a[2]],pnt[a[3]]);
    sort(len,len+6);
    if(len[0]==len[1] && len[2]==len[3] && len[4]==len[5] && len[0]+len[2]==len[4])return 1;
    return 0;
}
int main()
{
    int i,j,k,l,ii[4],cir,num;
    for(i=0;i<8;i++)scanf("%d%d",&pnt[i].x,&pnt[i].y);
    for(i=0;i<8;i++)
        for(j=i+1;j<8;j++)
            if(i!=j)
            for(k=j+1;k<8;k++)
                if(i!=k && j!=k)
                for(l=k+1;l<8;l++)
                    if(i!=l && j!=l && k!=l)
                    {
                        memset(bo,0,sizeof(bo));
                        bo[i]=bo[j]=bo[k]=bo[l]=1;
                        //cout<<"*****"<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<endl;
                        num=0;
                        for(cir=0;cir<8;cir++)
                            if(!bo[cir])ii[num++]=cir;
                        if(is1(i,j,k,l) && is2(ii))
                        {
                            puts("YES");
                            printf("%d %d %d %d\n",i+1,j+1,k+1,l+1);
                            printf("%d %d %d %d\n",ii[0]+1,ii[1]+1,ii[2]+1,ii[3]+1);
                            return 0;
                        }
                    }
    puts("NO");
    return 0;
}
