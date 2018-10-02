#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<cmath>
#include<string>
using namespace std;
int s[55];
int c[55][55];
int ans[5555][4];
int number[5555],num=0;
int times=0;
int main()
{
    int n,i,j,cnt=0,k,l;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",c[i]);
    for(i=0;i<n;i++)
        for(j=1;j<=c[i][0];j++)
        {
            scanf("%d",c[i]+j);
            number[num++]=c[i][j];
        }
    sort(number,number+num);
    for(i=0;i<n;i++)
        for(j=1;j<=c[i][0];j++)
        {
            if(number[cnt]!=c[i][j])
            {
                for(k=0;k<n;k++)
                    for(l=1;l<=c[k][0];l++)
                        if(number[cnt]==c[k][l])
                        {
                            swap(c[i][j],c[k][l]);
                            ans[times][0]=i+1;
                            ans[times][1]=j;
                            ans[times][2]=k+1;
                            ans[times][3]=l;
                            times++;
                            goto done;
                        }
                done:;
            }
            cnt++;
        }
    printf("%d\n",times);
    for(i=0;i<times;i++)
    {
        for(j=0;j<3;j++)printf("%d ",ans[i][j]);
        printf("%d\n",ans[i][3]);
    }
    return 0;
}
