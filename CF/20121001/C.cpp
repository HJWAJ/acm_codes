#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
using namespace std;
char s[105][30005];
int cnt[105][10005];
int main()
{
    int n,m,i,j,k,last,now,mmin=99999999,tmp;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%s",s[i]);
        for(j=0;j<m;j++)s[i][j+2*m]=s[i][j+m]=s[i][j];
    }
    for(i=0;i<n;i++)
    {
        for(j=m-1;j>=0;j--)
            if(s[i][j]=='1')
            {
                last=j;
                break;
            }
        if(j==-1)
        {
            puts("-1");
            exit(0);
        }
        for(j=last+1;j<3*m;j++)
        {
            if(s[i][j]=='1')
            {
                now=j;
                for(k=last+1;k<now;k++)
                    if(k>=m && k<2*m)
                    {
                        if(k-last<now-k)cnt[i][k-m]=k-last;
                        else cnt[i][k-m]=now-k;
                    }
                last=now;
            }
        }
    }
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)cout<<cnt[i][j]<<' ';
        cout<<endl;
    }*/
    for(i=0;i<m;i++)
    {
        tmp=0;
        for(j=0;j<n;j++)tmp+=cnt[j][i];
        if(tmp<mmin)mmin=tmp;
    }
    printf("%d\n",mmin);
    return 0;
}
