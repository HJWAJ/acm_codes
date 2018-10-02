#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int cnt,rec1[1000001],rec2[1000001];

int main()
{
    int n,a[301],b[301];
    while(scanf("%d",&n)!=EOF)
    {
        int i,j,k,flag;
        flag=cnt=0;
        for(i=0;i<n;i++)scanf("%d",a+i);
        for(i=0;i<n;i++)scanf("%d",b+i);
        for(i=0;i<n-1;i++)
        {
            if(a[i]!=b[i])
            {
                for(j=i+1;j<n;j++)
                {
                    if(b[j]==a[i])
                    {
                        for(k=j;k>i;k--)
                        {
                            cnt++;
                            swap(b[k],b[k-1]);
                            rec1[flag]=k;
                            rec2[flag++]=k+1;
                            //for(i=0;i<cnt;i++)printf("%d %d\n",rec1[i],rec2[i]);                
                        }              
                        break;
                    }                  
                }              
            }                
        }
        printf("%d\n",cnt);
        for(i=0;i<cnt;i++)printf("%d %d\n",rec1[i],rec2[i]);     
    }    
    
    return 0;
}
