#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

char a[101],b[101];
int dp[101][101];
int match[5][5]={{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,-10}};

int max(int x,int y,int z)
{
	int tmp;
	if(x<y)tmp=y;
	else tmp=x;
	if(tmp<z)return z;
	else return tmp;
}

int pos(char ch)
{
	if(ch=='A')return 0;
	else if(ch=='C')return 1;
	else if(ch=='G')return 2;
	else if(ch=='T')return 3;
	else if(ch=='-')return 4;
}

int main()
{
	int i,j,num;
	scanf("%d",&num);
	while(num--)
	{
		int m,n,len1,len2;
		scanf("%d%s",&m,a);
		scanf("%d%s",&n,b);
		len1=strlen(a);
		len2=strlen(b);
		dp[0][0]=0;
		for(i=1;i<=n;i++)dp[0][i]=dp[0][i-1]+match[pos(b[i-1])][pos('-')];
		for(i=1;i<=m;i++)dp[i][0]=dp[i-1][0]+match[pos(a[i-1])][pos('-')];
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				dp[i][j]=max(dp[i-1][j-1]+match[pos(a[i-1])][pos(b[j-1])],dp[i][j-1]+match[pos(b[j-1])][pos('-')],dp[i-1][j]+match[pos(a[i-1])][pos('-')]);  
		printf("%d\n",dp[m][n]);
	}
	
	return 0;
}

