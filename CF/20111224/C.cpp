#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<queue>
#include<string>
#include<vector>
using namespace std;
char s[4][10005];
int len[4],num[4],pos[4];
bool bo[3];
bool check(int a,int b)
{
    if(pos[a]==-1 || pos[b]==-1)return 0;
    if(strcmp(s[a]+pos[a],s[b]+pos[b]))return 0;
    return 1;
}
int main()
{
    int n,k,i,j,ii,flag=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<4;i++)bo[i]=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%s",s[j]);
            len[j]=strlen(s[j]);
            num[j]=0;pos[j]=-1;
            for(ii=len[j]-1;ii>=0;ii--)
                if(s[j][ii]=='a' || s[j][ii]=='e' || s[j][ii]=='i' || s[j][ii]=='o' || s[j][ii]=='u')
                {
                    num[j]++;
                    if(num[j]==k)
                    {
                        pos[j]=ii;
                        break;
                    }
                }
        }
        if(!(check(0,1) && check(2,3)))bo[0]=0;
        if(!(check(0,2) && check(1,3)))bo[1]=0;
        if(!(check(0,3) && check(1,2)))bo[2]=0;
    }
    if(bo[0] && bo[1] && bo[2])
    {
        puts("aaaa");
        flag=1;
    }
    else
    {
        if(bo[0])
        {
            flag=1;
            puts("aabb");
        }
        if(bo[1])
        {
            flag=1;
            puts("abab");
        }
        if(bo[2])
        {
            puts("abba");
            flag=1;
        }
    }
    if(!flag)puts("NO");
    return 0;
}
