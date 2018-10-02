#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<cmath>
#include<string>
using namespace std;
int next[2005],num[2005],father[2005];
void make_set(int n)
{
	father[0]=0;
	num[0]=0;
	for(int i=1;i<=n;++i)
	{
		father[i]=i;
		num[i]=1;
	}
	memset(next,0,sizeof(next));
}
int find_set(int x)
{
	while(x!=father[x])
		x=father[x];
	return x;
}
int Union(int x,int y)
{
	next[x]=next[y]=0;
	if(x==y) return x;
	if(num[x]>num[y])
	{
		father[y]=x;
		num[x]+=num[y];
		num[y]=0;
		return x;
	}
	else
	{
		father[x]=y;
		num[y]+=num[x];
		num[x]=0;
		return y;
	}
}
int main()
{
	int t,tt=0,n,m,flag,a,b,k1,k2,next1,next2;
	scanf("%d",&t);
	while(t--)
	{
	    tt++;
		flag=0;
		scanf("%d%d",&n,&m);
		make_set(n);
		while(m--)
		{
			scanf("%d%d",&a,&b);
			if(a>n||b>n) flag=1;
			a=find_set(a);
			b=find_set(b);
			if(a==b) flag=1;
			else if(next[a]!=0&&next[b]!=0)
			{
				next1=next[a];
				next2=next[b];
				k1=Union(next1,b);
				k2=Union(next2,a);
				next[k1]=k2;
				next[k2]=k1;
			}
			else if(next[a]!=0)
			{
				k1=Union(next[a],b);
				next[k1]=a;
				next[a]=k1;
			}
			else if(next[b]!=0)
			{
				k1=Union(next[b],a);
				next[k1]=b;
				next[b]=k1;
			}
			else
			{
				next[a]=b;
				next[b]=a;
			}
		}
		if(flag)printf("Scenario #%d:\nSuspicious bugs found!\n\n",tt);
		else printf("Scenario #%d:\nNo suspicious bugs found!\n\n",tt);
	}
	return 0;
}
