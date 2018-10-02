#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;


struct mina{
	long start,end;
	long len;
};



struct minb{
	short member;
	long distance;
};



int main()
{
	int n0,i0,j0,m,i,j,inqueue,score;
	int way[501][501];
	mina min;
	minb queue[501];
	bool ok[501];
	

	cin>>n0;
	while (n0)
	{   n0--;
		memset(way,-1,sizeof(way));
		memset(queue,0,sizeof(queue));
	   cin>>m;
		for (i0=1;i0<=m;i0++)
	   	  for (j0=1;j0<=m;j0++)
		   {
			   scanf("%d", &way[i0][j0]);
			  
		   }                                  //初始化数据 输入可连通路及距离
	   
	   
		   
		 
		   queue[1].member=1;
		   inqueue=1;
		   memset(ok,1,sizeof(ok));
		   ok[1]=0;

		   while (inqueue<m)
		   {
               
		
			   min.start=0;   min.end=0;
			   min.len=0x7fffffff;     //0x7fffffff
			   for (i=1;i<=inqueue;i++)
				   for (j=1;j<=m;j++)
				   {   				   
				   
				   if ((way[queue[i].member][j] != 0)&&
					   (way[queue[i].member][j]<=min.len) &&
					   (ok[j]))
				   {
					   min.start=queue[i].member;
					   min.end=j;
					   min.len=way[queue[i].member][j];
				   }
				   }	
				   
				   queue[inqueue+1].distance=min.len;
				   queue[inqueue+1].member=min.end; 
				   ok[min.end]=false;
				   
				   inqueue+=1;
				   
		   }
		   
		   score=0;
		   for (i=1;i<=inqueue;i++)
		   {
			   if (score<=queue[i].distance)

			   {score=queue[i].distance;}
		   }
		   
		   
		   printf("%d", score);
		   
				   
	
		   cout<<endl;
	}
	
	
	
	return 0;
}
