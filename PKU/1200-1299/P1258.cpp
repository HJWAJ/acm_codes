#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

struct tree
{
    int x,y,dist;       
}t[10050];

int main()
{
    int n,dis[105][105],i,j,k,sum,min,x,y;
    bool val[105];
    while(scanf("%d",&n)!=EOF)
    {
        memset(val,0,sizeof(val));
        val[0]=1;
        sum=0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                scanf("%d",&dis[i][j]);
                if(i==j)dis[i][j]=0x7fffffff;
            }
        for(i=0;i<n-1;i++)
        {
            min=0x7fffffff;
            for(j=0;j<n;j++)
            {
                if(val[j]==1)
                {
                    for(k=0;k<n;k++)
                    {
                        if(dis[j][k]<min && val[k]==0)
                        {
                            min=dis[j][k];
                            x=j;
                            y=k;    
                        }                
                    }             
                }                
            }
            val[x]=val[y]=1;
            sum+=min;
        }
        printf("%d\n",sum);
    }
    
    return 0;
}
