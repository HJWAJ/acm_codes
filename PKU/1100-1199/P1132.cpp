#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int t,x,y,i,j,len,tt=0;
	char map[50][50],s[10000];
	scanf("%d",&t);
	while(t--)
	{
	    tt++;
		printf("Bitmap #%d\n",tt);
		memset(map,0,sizeof(map));
		memset(s,0,sizeof(s));
		scanf("%d%d",&x,&y);
		i=0;
		getchar();
		while(scanf("%c",&s[i]) && s[i]!='.')i++;
		getchar();
		len=i;
		for(i=0;i<=32;i++)
			for(j=0;j<=32;j++)
				map[i][j]='.';
		for(i=0;i<len;i++)
		{
		    if(s[i]=='E')
			{
			    x++;
				map[y][x]='X';
			}
			if(s[i]=='W')
			{
				x--;
				map[y+1][x+1]='X';
			}
			if(s[i]=='N')
			{
				y++;
				map[y][x+1]='X';
			}
			if(s[i]=='S')
			{
				y--;
				map[y+1][x]='X';
			}
		}
		for(i=32;i>0;i--)
		{
			for(j=1;j<=32;j++)
				printf("%c",map[i][j]);
			printf("\n");
		}
		printf("\n");
	}

    return 0;
}
