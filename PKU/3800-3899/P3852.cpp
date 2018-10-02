#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int min(int x,int y)
{
    return x<y?x:y;    
}

int mylen(char s[][105],int len[],int x,int y)
{
    int i;
    if(len[x]!=len[y])return min(len[x],len[y]);
    for(i=len[x]-1;i>=0;i--)
        if(s[x][i]!=s[y][i])break;
    return i+1;
}

int main()
{
    char s[100][105];
    int len[100],n,i,j,cnt[100][100],mini;
    while(scanf("%d",&n) && n)
    {
        mini=999999;
        for(i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            len[i]=strlen(s[i]);
        }
        if(n==1)
        {
            printf("%d\n",len[0]-1);
            continue;
        }
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                if(i==j)continue;
                cnt[i][j]=mylen(s,len,i,j);
                if(mini>cnt[i][j])mini=cnt[i][j];
            }
        printf("%d\n",mini-1);
    }    
    
    return 0;
}
