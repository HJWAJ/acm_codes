#include<iostream>
using namespace std;

int a[510][30010],c[30010];

int main()
{
	int i,j,k,m,n,b[501],p;
	while(cin>>n>>m&&(m!=0||n!=0))
	{
		k=0;
		for(i=1;i<=m;i++)
		{
			cin>>b[i];
			a[i][0]=0;
			for(j=1;j<=b[i];j++)
			{
				cin>>a[i][j];
				if(!a[i][j])
				{
					a[k][0]=0;
					k=i;
					a[i][0]=1;
				}
			}
		}
		for(i=1;i<n;i++)a[0][i]=1;
		a[0][0]=0;
		c[0]=0;
		p=1;
		for(j=1;j<=b[k]&&k;j++)
			if(a[0][a[k][j]]){
				c[p++]=a[k][j];
				a[0][a[k][j]]=0;
			}
		for(i=0;i<p;i++)
		{
			for(k=1;k<=m;k++)
			{
				if(a[k][0])continue;
				for(j=1;j<=b[k];j++)if(a[k][j]==c[i])break;
				if(j<=b[k])for(j=1;j<=b[k];j++)
					if(a[0][a[k][j]])
					{
						c[p++]=a[k][j];
						a[0][a[k][j]]=0;
					}
			}
		}
		cout<<p<<endl;
	}
	return 0;
}

