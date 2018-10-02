#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
int a[1000005],d[1000005];
int l[100005],r[100005];
int main()
{
    int n,m,i,j,len,tmp,nowl,flag;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        len=0;
        memset(d,0,sizeof(d));
        for(i=0;i<m;i++)
        {
            scanf("%d%d",l+i,r+i);
            d[l[i]]++;
            d[r[i]+1]--;
        }
        for(i=1;i<=n;i++)d[i]+=d[i-1];
        for(i=1;i<=n;i++)
        {
            if(d[i])
            {
                for(j=m-1;j>=0;j--)
                    if(i>=l[j] && i<=r[j])
                    {
                        a[i]=j+1;
                        break;
                    }
            }
            else a[i]=0;
        }
        tmp=a[1];
        flag=1;
        for(i=2;i<=n;i++)
            if(tmp!=a[i])
            {
                nowl=i-flag;
                if(nowl>len && tmp)len=nowl;
                tmp=a[i];
                flag=i;
            }
        nowl=i-flag;
        if(nowl>len && tmp)len=nowl;
        printf("%d\n",len);
    }
    return 0;
}
