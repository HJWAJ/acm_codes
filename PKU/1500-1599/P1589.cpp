#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
char s[101][101];
int cmp (const void *a,const void *b) 
{ 
	return strcmp((char *)a,(char *)b); 
}
int main()
{
	int i,j,k,m,n,t,r,x;
	while(scanf("%d",&n)!=EOF)
	{
		k=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",s[i]);
			j=strlen(s[i]);
			if(j>k)
				k=j;
		}
		qsort(s,n,sizeof(s[0]),cmp);
		k+=2;
		t=62/k;
		r=(n+t-1)/t;
		t=(n+r-1)/r;
		printf("------------------------------------------------------------\n");
		for(i=0;i<r;i++)
		{
			for(j=0;j<t;j++)
			{
				if(i+r*j>=n)
					break;
				printf("%s",s[i+r*j]);
				x=k-strlen(s[i+r*j]);
				for(m=0;m<x;m++)
					printf(" ");
			}
			printf("\n");
		}
	}
	
	system("pause");
	return 0;
}
