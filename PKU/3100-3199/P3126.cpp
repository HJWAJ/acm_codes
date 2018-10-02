#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

bool vis[10000];
bool isprime[10000];

typedef struct
{
	int num;
	int step;
}Node;

int pow(int n)
{
	int ret=1;

	while(n--)
		ret*=10;

	return ret;
}

void bfs(int start,int end,int& minstep)
{
	int i,j,out;
	Node temp,next;
	queue<Node> Q;

	if(start==end)
	{
		minstep=0;
		return;
	}

	temp.num=start;
	vis[temp.num]=true;
	temp.step=0;
	Q.push(temp);

	while(!Q.empty())
	{
		temp=Q.front();
		Q.pop();

		for(i=3;i>=0;i--)
		{
			out=0;
			out+=(temp.num)/pow(i+1)*pow(i+1);
			out+=(temp.num)%pow(i);

			for(j=0;j<=9;j++)
			{
				next.num=out+j*pow(i);
				next.step=temp.step+1;

				if(!vis[next.num]&&isprime[next.num])
				{
					if(next.num==end)
					{
						minstep=next.step;
						return;
					}
					vis[next.num]=true;
					Q.push(next);
				}
			}
		}
	}
}

int main()
{
	int i,j;
	int cases;
	bool flag;

	int prime[1100];
	int primenum;
	int minstep;
	int start;
	int end;

	for(i=0;i<10000;i++)
		isprime[i]=false;

	primenum=0;
	for(j=1000;j<=9999;j++)
	{
		flag=true;
		for(i=2;i<=(int)sqrt(1.0*j);i++)
			if(j%i==0)
			{
				flag=false;
				break;
			}

		if(flag)
			prime[primenum++]=j;
	}

	for(i=0;i<primenum;i++)
		isprime[prime[i]]=true;

	cin>>cases;
	while(cases--)
	{
		for(i=0;i<10000;i++)
			vis[i]=false;
		cin>>start>>end;
		bfs(start,end,minstep);

		cout<<minstep<<endl;
	}

	return 0;
}
