#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<queue>
#include<string>
#include<vector>
using namespace std;
char s[100005],p[100005];
int bo[300],cnt[300],boo[300],cntt[300];
int main()
{
    scanf("%s%s",s,p);
    int lens=strlen(s);
    int lenp=strlen(p);
    int i,j,num=0;
    if(lens<lenp)
    {
        puts("0");
        return 0;
    }
    memset(bo,0,sizeof(bo));
    memset(boo,0,sizeof(boo));
    memset(cnt,0,sizeof(cnt));
    memset(cntt,0,sizeof(cntt));
    for(i=0;i<lenp;i++)cnt[p[i]]++;
    for(i=0;i<lenp;i++)bo[s[i]]++;
    memmove(boo,bo,sizeof(bo));
    memmove(cntt,cnt,sizeof(cnt));
    for(i=0;i<=lens-lenp;i++)
    {
        memmove(bo,boo,sizeof(bo));
        memmove(cnt,cntt,sizeof(cnt));
        for(j=0;j<300;j++)
        {
            if(bo[j]>cnt[j] && j!=63)break;
            else if(bo[j]==cnt[j])continue;
            else if(bo[j]<cnt[j])
            {
                cnt[j]-=bo[j];
                if(cnt[j]>bo['?'])break;
                else bo['?']-=cnt[j];
            }
        }
        if(j==300)num++;
        //cout<<boo['a']<<' '<<boo['b']<<endl;
        if(i!=lens-lenp)
        {
            boo[s[i]]--;
            boo[s[i+lenp]]++;
        }
    }
    printf("%d\n",num);
    return 0;
}
