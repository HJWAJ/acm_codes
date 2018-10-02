#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool a[105][105],b[105][105],val;
int ver1[105],hor1[105],gra1[105],ver2[105],hor2[105],gra2[105];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        val=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(ver1,0,sizeof(ver1));
        memset(hor1,0,sizeof(hor1));
        memset(gra1,0,sizeof(gra1));
        memset(ver2,0,sizeof(ver2));
        memset(hor2,0,sizeof(hor2));
        memset(gra2,0,sizeof(gra2));
        int w,h,n,x1,x2,y1,y2,i,j,cnt;
        scanf("%d%d%d",&w,&h,&n);
        for(i=0;i<n;i++)
            {
                scanf("%d%d",&x1,&y1);
                a[y1][x1]=1;               
            }
        for(i=0;i<n;i++)
            {
                scanf("%d%d",&x2,&y2);
                b[y2][x2]=1;               
            }
        
        for(i=0;i<h;i++)
            for(j=0;j<w;j++)
            {
                cnt=0;
                if(a[i][j]==1)
                {
                    while(a[i][j+cnt]==1)cnt++;
                    ver1[cnt]++;
                }
            }
        for(i=0;i<h;i++)
            for(j=0;j<w;j++)
            {
                cnt=0;
                if(b[i][j]==1)
                {
                    while(b[i][j+cnt]==1)cnt++;
                    ver2[cnt]++;
                }
            }
        for(j=0;j<w;j++)
            for(i=0;i<h;i++)
            {
                cnt=0;
                if(a[i][j]==1)
                {
                    while(a[i+cnt][j]==1)cnt++;
                    hor1[cnt]++;
                }
            }
        for(j=0;j<w;j++)
            for(i=0;i<h;i++)
            {
                cnt=0;
                if(b[i][j]==1)
                {
                    while(b[i+cnt][j]==1)cnt++;
                    hor2[cnt]++;
                }
            }
        for(i=0;i<105;i++)
        {
            gra1[i]=hor1[i]+ver1[i];
            gra2[i]=hor2[i]+ver2[i];
            if(gra1[i]!=gra2[i]){val=1;break;}
        }
        if(val==0)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
