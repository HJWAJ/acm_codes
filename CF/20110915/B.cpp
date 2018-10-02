#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
    int m,n,i,j,cnt=0;
    char s[15][15];
    bool bo[15][15];
    memset(bo,0,sizeof(bo));
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)scanf("%s",s[i]);
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(s[i][j]=='W')
            {
                if(i>0 && s[i-1][j]=='P' && !bo[i-1][j])
                {
                    bo[i-1][j]=1;
                    cnt++;
                    continue;
                }
                if(j>0 && s[i][j-1]=='P' && !bo[i][j-1])
                {
                    bo[i][j-1]=1;
                    cnt++;
                    continue;
                }
                if(i<m && s[i+1][j]=='P' && !bo[i+1][j])
                {
                    bo[i+1][j]=1;
                    cnt++;
                    continue;
                }
                if(j<n && s[i][j+1]=='P' && !bo[i][j+1])
                {
                    bo[i][j+1]=1;
                    cnt++;
                    continue;
                }
            }
    printf("%d\n",cnt);
    return 0;
}
