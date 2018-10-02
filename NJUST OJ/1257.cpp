#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<vector>
using namespace std;
int prime[200005];
bool bo[1000005];
int cnt[1000005];
int prime_table()
{
    int i,j,flag=0;
    memset(bo,0,sizeof(bo));
    bo[0]=bo[1]=1;
    for(i=2;i<=1000000;i++)
        if(!bo[i])
        {
            prime[flag++]=i;
            j=i+i;//j=i+i ´ý²â
            for(;j<=1000000;j+=i)bo[j]=1;
        }
    return flag;
}
int dfs(int n)
{
    int i;
    if(cnt[n])return cnt[n];
    if(!bo[n])return cnt[n]=1;
    for(i=0;prime[i]<=n;i++)
        if(n%prime[i]==0)
            return cnt[n]=dfs(n/prime[i])+1;
}
struct point
{
    double x,y,z;
}pnt[205];
inline double dis(point a,point b)
{
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z) );
}
double fermat_point(point pt[],int n,point& ptres)
{
	point u,v;
	double step=0.0,curlen,explen,minlen;
	int i,j,k,kk,idx;
	bool flag;
	u.x=u.y=u.z=v.x=v.y=v.z=0.0;
	for(i=0;i<n;i++)
	{
		step+=fabs(pt[i].x)+fabs(pt[i].y)+fabs(pt[i].z);
		u.x+=pt[i].x;
		u.y+=pt[i].y;
		u.z+=pt[i].z;
	}
	u.x/=n;
	u.y/=n;
	u.z/=n;
	flag=0;
	while(step>1e-10)
	{
		for(k=0;k<10;step/=2,k++)
			for(i=-1;i<=1;i++)
				for(j=-1;j<=1;j++)
                    for(kk=-1;kk<=1;kk++)
                    {
                        v.x=u.x+step*i;
                        v.y=u.y+step*j;
                        v.z=u.z+step*kk;
                        curlen=explen=0.0;
                        for(idx=0;idx<n;idx++)
                        {
                            curlen+=dis(u,pt[idx]);
                            explen+=dis(v,pt[idx]);
                        }
                        if(curlen>explen)
                        {
                            u=v;
                            minlen=explen;
                            flag=1;
                        }
                    }
	}
	ptres=u;
	return flag?minlen:curlen;
}
int main()
{
    int n,a,b,c,i;
    double ans;
    point anspnt;
    memset(cnt,0,sizeof(cnt));
    prime_table();
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            pnt[i].x=dfs(a);
            pnt[i].y=dfs(b);
            pnt[i].z=dfs(c);
        }
        ans=fermat_point(pnt,n,anspnt);
        printf("%.2lf\n",ans);
    }
    return 0;
}
