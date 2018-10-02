#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int M=105;
int degree[M];
bool bo[M];

int main()
{
    int x,y,t=0,val,node,side;
	while(scanf("%d%d",&x,&y) && !(x<0 && y<0))
	{
		if(x==0 || y==0)
		{
			printf("Case %d is a tree.\n",++t);
			continue;
		}
		memset(degree,0,sizeof(degree));
		memset(bo,-1,sizeof(bo));
		degree[y]++;	
        val=1;
		side=1;
		node=2;
		bo[x]=bo[y]=0;
		if(x==y)val=0;
		while(scanf("%d%d",&x,&y) && (x || y))
		{
			degree[y]++;
			if(degree[y]>1)val=0;
			if(bo[x]){bo[x]=0;node++;}
			if(bo[y]){bo[y]=0;node++;}
			side++;
		}
		if(node!=side+1)val=0;
		if(val)printf("Case %d is a tree.\n",++t);
		else printf("Case %d is not a tree.\n",++t);
	}
	
	return 0;
}

