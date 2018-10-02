#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const __int64 M=432;
__int64 prim[M];
__int64 f[M][M];
bool val[M];
int main()
{
	__int64 t,i,j,n,k,sum,p;
    memset(val,true,sizeof(val));
	t=0;
	for(i=2;i<M;i++)
		if(val[i])
		{
			p=prim[++t]=i;
			while(p<M)
            {
                val[p]=false;
                p+=i;
            }
		}

	memset(f,0,sizeof(f));
	for(i=2;i<M;i++)
		for(j=1;j<=t;j++)
			f[i][j]=f[i/prim[j]][j]+i/prim[j];
			
	while(scanf("%I64d%I64d",&n,&k)!=EOF)
	{
		sum=1;
		for(i=1;i<=t;i++)
			sum*=f[n][i]-f[n-k][i]-f[k][i]+1;
		printf("%I64d\n",sum); 
	}
	return 0;
}
