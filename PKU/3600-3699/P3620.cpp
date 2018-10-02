#include<iostream>
#include<cstring>
using namespace std;

int a[102][102],r,c,i,j,k;

int dfs(int x,int y)
{
	if(x<1 || x>r || y<1 || y>c || a[x][y]==0)return 0;
	a[x][y]=0;
	return 1+dfs(x-1,y)+dfs(x+1,y)+dfs(x,y-1)+dfs(x,y+1);
}

int main()
{
	int max=-1,num=-1;
    scanf("%d%d%d",&r,&c,&k);
	memset(a,0,sizeof(a));
	while(k--)
    {
	    scanf("%d%d",&i,&j);
        a[i][j]=1;
    }
	for(i=1;i<=r;i++)
		for(j=1;j<=c;j++)
        {
			if(a[i][j])num=dfs(i,j);
			if(max<num)max=num;
		}
	printf("%d\n",max);
	
	return 0;
}

