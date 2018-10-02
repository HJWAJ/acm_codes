#include<iostream>
#include<cstdio>
using namespace std;
struct nod
{ 
	int x; int y; 
}s[100000]; 

int cmp(const void *a,const void *b ) 
{ 
    struct nod *c =(nod *)a; 
    struct nod *d =(nod *)b; 
    if(c->x != d->x) return c->x - d->x; 
    else return c->y - d->y; 
} 

int main()
{
	int n,m,k,t,i,j;
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for(i=0;i<k;i++)scanf("%d%d",&s[i].x,&s[i].y);
	int bo=k;
	for(i=0;i<t;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		s[bo].x=a;
		s[bo].y=b;
		qsort(s,k+1,sizeof(s[0]),cmp);
		s[k+1].x=0;
		s[k+1].y=0;
		for(j=0;j<=k;j++)if(s[j].x==a && s[j].y==b) break;
        if(s[j].x==s[j+1].x && s[j].y==s[j+1].y)printf("Waste\n");
		else
		{
		    if(((s[j].x-1)*m+s[j].y-j)%3==0)printf("Grapes\n");
		    else if(((s[j].x-1)*m+s[j].y-j)%3==1)printf("Carrots\n");
		    else printf("Kiwis\n");
		}
		bo=j;
	}
	
	return 0;
}
