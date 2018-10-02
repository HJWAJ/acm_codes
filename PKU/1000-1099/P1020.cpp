#include<iostream>
using namespace std;
int c[11],d[41],s,n,sum;
bool ok;
void dfs(int a)
{
	int i,j,put,p;
	bool f;
	if(ok!=0)return;
	if(a==n){ok=1;exit;}
	for(i=1,put=41;i<=s;i++)if(d[i]<put){put=d[i];p=i;}
	for(i=10;i>=1;i--)
		if(c[i]>0 && put+i-1<=s && p+i-1<=s)
		{
			for(j=p,f=1;j<=p+i-1;j++)if(d[j]>put){f=0;break;}
			if(f!=0)
			{
				for(j=p;j<=p+i-1;j++)d[j]+=i;
				c[i]--;
				dfs(a+1);
				c[i]++;
				for(j=p;j<=p+i-1;j++)d[j]-=i;
			}
		}
}
int main()
{
	int t,it,i,tp;
	cin>>t;
	for(it=1;it<=t;it++)
	{
		cin>>s>>n;
		memset(c,0,sizeof(c));
		for(i=1;i<=40;i++) d[i]=1;
		sum=0;
		for(i=1;i<=n;i++)
		{
			cin>>tp;
			c[tp]++;
			sum+=tp*tp;
		}
		if(sum!=s*s) ok=0;
		else {ok=0;dfs(0);}
		if(ok) cout<<"KHOOOOB!"<<endl;
		else cout<<"HUTUTU!"<<endl;
	}
	system("pause");
	return 0;
}
