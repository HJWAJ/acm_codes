#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
 
bool f[705][705];
int a[705];
 
int main()
{
    int n,i,j,s,num,maxn,x[705],y[705],t,m;	
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<=n-1;i++)scanf("%d%d",&x[i],&y[i]);
        maxn=-1;
        for(i=0;i<=n-1;i++)
            for(j=i;j<=n-1;j++)
                f[i][j]=0;
        for(i=0;i<=n-1;i++)
        {
            for(j=i+1;j<=n-1;j++)
            {
                if(f[i][j]==1)continue;
                if(n-j<maxn)break;
                num=2;
                t=2;
                a[0]=i;
                a[1]=j;
                f[i][j]=1; 
                for(s=j+1;s<=n-1;s++)
                {
                    if(f[i][s]==1 || f[j][s]==1)continue;
                    if((y[i]-y[s])*(x[j]-x[s])==(x[i]-x[s])*(y[j]-y[s]))
                    {
                        num++;	
                        a[t]=s;
                        for(m=0;m<=t-1;m++)f[m][s]=1;
                        t++;	
                    }
                }
                if(num>maxn)maxn=num;	
            }
        }
        printf("%d\n",maxn);			
    }
    
    //system("pause");
    return 0;
}
