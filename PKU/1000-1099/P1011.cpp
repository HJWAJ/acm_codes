#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

int sticks[65];
bool used[65];

bool DFS(int total,int unused,int left,int len)
{
    int i;
	if(unused==0&&left==0)return 1;
	if(left==0)left=len;
	for(i=0;i<total;i++)
	{
   	    if(used[i]==1)continue;
   		if(sticks[i]>left)continue;
   		used[i]=1;
   		if(DFS(total,unused-1,left-sticks[i],len)!=0)return 1;
   		used[i]=0;
   		if(sticks[i]==left||left==len)break;
	}
	return 0;
}

int cmp(const void* a,const void* b)
{
    return *(int*)b-*(int*)a;
}

int main()
{
    int n;
	scanf("%d",&n);
	while(n!=0)
	{
        int i,sum=0,len;
   		for(i=0;i<n;i++)
   		{
    	    used[i]=false;
    		scanf("%d",&sticks[i]);
    		sum+=sticks[i];
	    }
   		qsort(sticks,n,sizeof(int),cmp);
   		len=sticks[0];
   		for(i=len;i<=sum;i++)
   		{
    	    if(sum%i!=0)continue;
    		if(DFS(n,n,0,i))
    		{
     		    printf("%d\n",i);
     			break;
   			}
        }
   		scanf("%d",&n);
	}
	
	system("pause");
	return 0;
}
