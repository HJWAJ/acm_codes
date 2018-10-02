#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int a[105][105];
int cnt[105];
bool bo[105];
bool boo[105];
int flag=-1;
int num;
int main()
{
    int n,m,u,v,i,j,k,tmp;
    scanf("%d%d",&n,&m);
    memset(a,0,sizeof(a));
    memset(cnt,0,sizeof(cnt));
    memset(boo,0,sizeof(boo));
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        a[u-1][cnt[u-1]++]=v-1;
        a[v-1][cnt[v-1]++]=u-1;
    }
    do
    {
        flag++;
        num=0;
        memset(bo,0,sizeof(bo));
        for(i=0;i<n;i++)
        {
            if(cnt[i]==1 && !boo[i])
            {
                num=1;
                bo[i]=1;
                boo[i]=1;
                //cout<<i+1<<endl;
                cnt[i]--;
            }
        }
        //system("pause");
        for(i=0;i<n;i++)
            if(bo[i])
            {
                tmp=a[i][0];
                for(j=0;j<cnt[tmp];j++)
                    if(a[tmp][j]==i)
                    {
                        for(k=j+1;k<cnt[tmp];k++)a[tmp][k-1]=a[tmp][k];
                        cnt[tmp]--;
                        //cout<<cnt[tmp]<<endl;
                        break;
                    }
            }
        //system("pause");
    }while(num);
    printf("%d\n",flag);
    return 0;
}
