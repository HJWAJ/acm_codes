#include<iostream>
using namespace std;

const int MAX=100;
const int BASE=10000;

void Multiply(int a[],int len,int b)
{
	for(int i=len-1,carry=0;i>=0;i--)
    {
		carry+=b*a[i];
		a[i]=carry%BASE;
		carry/=BASE;
	}
}

void Divide(int a[],int len,int b)
{
	for(int i=0,div=0;i<len;i++)
    {
		div=div*BASE+a[i];
		a[i]=div/b;
		div%=b;
	}
}

int main()
{
	int i,j,h[110][MAX];
	memset(h[1],0,MAX*sizeof(int));
	for(i=2,h[1][MAX-1]=1;i<=102;i++)
    {
		memcpy(h[i],h[i-1],MAX*sizeof(int));
		Multiply(h[i],MAX,4*i-6);
		Divide(h[i],MAX,i);
	}
	while(scanf("%d",&i) && i!=-1)
    {
		i++;
		for(j=0;j<MAX && h[i][j]==0;j++);
		for(printf("%d",h[i][j++]);j<MAX;j++)
			printf("%04d",h[i][j]);
		printf("\n");
	}
	return 0;
}

