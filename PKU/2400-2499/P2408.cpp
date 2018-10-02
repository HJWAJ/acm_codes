#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<fstream>
using namespace std;
struct nod
{
    char s[105];
    int len;
    int num;
}node[100005];
struct dist
{
    int num,biaoji,biaoji2;
    char s[200];
}dis[100005];
int cmp(const void *p,const void *q)
{
    nod *a=(nod *)p;
    nod *b=(nod *)q;
    if(a->len!=b->len)return a->len - b->len;
    else if(strcmp(a->s,b->s))return strcmp(a->s,b->s);
    return a->num - b->num;
}
int cmp2(const void *p,const void *q)
{
    dist *a=(dist *)p;
    dist *b=(dist *)q;
    if(a->num!=b->num) return b->num - a->num;
    else if(strcmp(a->s,b->s))return strcmp(a->s,b->s);
}
int cmp3(const void *p,const void *q)
{
    return strcmp((char *)p,(char *)q);
}
char ss[100005][105];
int main()
{
    int i,j,k,n=0;
    while(scanf("%s",ss[n])!=EOF)n++;
    qsort(ss,n,105,cmp3);
    /*
    j=0;
    i=1;
    while(i<n)
    {
        while(!strcmp(ss[i],ss[j]))i++;
        strcpy(ss[j+1],ss[i]);
        j++;         
    }
    n=j;
    */
    for(i=0;i<n;i++)
    {
        strcpy(node[i].s,ss[i]);
        node[i].num=i;
        node[i].len=strlen(node[i].s);
        sort(node[i].s,node[i].s+node[i].len);
    }
    qsort(node,n,sizeof(node[0]),cmp);
    int cnt[100005],flag=1,flag2=0;
    cnt[0]=0;
    for(i=1;i<n;i++)
        if(strcmp(node[i].s,node[i-1].s))
        {
            cnt[flag]=i;
            flag++;
        }
		cnt[flag]=n;
		flag++;
		for(i=1;i<flag;i++)
		{
			dis[flag2].num=cnt[i]-cnt[i-1];
			strcpy(dis[flag2].s,ss[node[cnt[i-1]].num]);
			dis[flag2].biaoji=cnt[i-1];
			dis[flag2].biaoji2=cnt[i]-1;
			flag2++;
		}
		qsort(dis,flag2,sizeof(dis[0]),cmp2);
		int aa,bb;
		char str[200];
		for(i=0;i<flag2-1&&i<4;i++)
		{
			printf("Group of size %d: ",dis[i].num);
			aa=dis[i].biaoji;
			bb=dis[i].biaoji2;
			strcpy(str,ss[node[aa].num]);
			printf("%s ",str);
			for(j=aa+1;j<=bb;j++)
			{
                    if(strcmp(str,ss[node[j].num])!=0)
  	                {
                      printf("%s ",ss[node[j].num]);
                      strcpy(str,ss[node[j].num]);
                   }
            }
			printf(".\n");
		}
		    printf("Group of size %d: ",dis[i].num);
			aa=dis[i].biaoji;
			bb=dis[i].biaoji2;
			strcpy(str,ss[node[aa].num]);
			printf("%s ",str);
			for(j=aa+1;j<=bb;j++)
			{
                    if(strcmp(str,ss[node[j].num])!=0)
  	                {
                      printf("%s ",ss[node[j].num]);
                      strcpy(str,ss[node[j].num]);
                   }
            }
			printf(".\n");
		//system("pause");
		return 0;
}
