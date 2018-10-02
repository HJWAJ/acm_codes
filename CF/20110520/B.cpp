#include <iostream>
#include <queue>
using namespace std;
struct node 
{
	__int64 t;
	int id;
};
queue <node> q1,q2,q3,p1,p2,p3,o;
__int64 a[100005],maxx;
int main()
{
	int i,j,k;
	__int64 w1,w2,w3,now,min;
	int s1,s2,s3,n,m,id,ns1,ns2,ns3;
	node b,c;
	while (scanf("%d%d%d",&s1,&s2,&s3)!=EOF)
	{
		maxx=-1;
		scanf("%I64d%I64d%I64d",&w1,&w2,&w3);
		scanf("%d",&n);
		while (!o.empty())
		{
			o.pop();
		}
		while (!q1.empty())
		{
			q1.pop();
		}
		while (!q2.empty())
		{
			q2.pop();
		}
		while (!q3.empty())
		{
			q3.pop();
		}
		while (!p1.empty())
		{
			p1.pop();
		}
		while (!p2.empty())
		{
			p2.pop();
		}
		while (!p3.empty())
		{
			p3.pop();
		}
		now=0;
		for (i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			b.id=i;
			b.t=a[i];
			o.push(b);
		}
		ns1=ns2=ns3=0;
		while (n)
		{
			min=-1;
			if (!q3.empty()&&(min==-1||q3.front().t<min))
			{
				id=3;
				min=q3.front().t;
			}
			if (!q2.empty()&&(min==-1||q2.front().t<min))
			{
				id=2;
				min=q2.front().t;
			}
		//	if (!q1.empty())
		//		printf("%I64d\n",q1.front().t);
			if (!q1.empty()&&(min==-1||q1.front().t<min))
			{
				id=1;
				min=q1.front().t;
			}
			if (!o.empty()&&(min==-1||o.front().t<min))
			{
				id=0;
				min=o.front().t;
			}
			now=min;
		//	printf("%I64d %d %d%d%d\n",now,id,ns1,ns2,ns3);
		//	cout<<now<<' '<<id<<endl;
			if (id==3)
			{
				ns3--;
				b=q3.front();
				q3.pop();
				if (now-a[b.id]>maxx)
					maxx=now-a[b.id];
				n--;
				if (!p3.empty())
				{
					b=p3.front();
					p3.pop();
					b.t=now+w3;
					q3.push(b);
					ns3++;
				}
			}
			if (id==2)
			{
				ns2--;
				b=q2.front();
				q2.pop();
				if (ns3<s3)
				{
					b.t=now+w3;
					q3.push(b);
					ns3++;
				}
				else
				{
					p3.push(b);
				}
				if (!p2.empty())
				{
					b=p2.front();
					p2.pop();
					b.t=now+w2;
					q2.push(b);
					ns2++;
				}
			}
			if (id==1)
			{
				ns1--;
				b=q1.front();
				q1.pop();
				if (ns2<s2)
				{
					b.t=now+w2;
				//	printf("%I64d %d\n",b.t,b.id);
					q2.push(b);
					ns2++;
				}
				else
				{
					p2.push(b);
				}
				if (!p1.empty())
				{
					b=p1.front();
					p1.pop();
					b.t=now+w1;//printf("%I64d %d\n",b.t,b.id);
					q1.push(b);
					ns1++;
				}
			}
			if (id==0)
			{
				b=o.front();
				o.pop();
				if (ns1<s1)
				{
					b.t=now+w1;
					q1.push(b);
					ns1++;
				}
				else
				{
					p1.push(b);
				}
			}
		}
		printf("%d\n",maxx);
	}
	while(1);
	return 0;
}
