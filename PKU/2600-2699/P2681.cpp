#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main()
{
    int t,tt=0,len1,len2,i,bo[30],sum;
    char s1[1005],s2[1005];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        tt++;
        gets(s1);
        gets(s2);
        memset(bo,0,sizeof(bo));
        len1=strlen(s1);
        len2=strlen(s2);
        sum=0;
        for(i=0;i<len1;i++)bo[s1[i]-'a']++;
        for(i=0;i<len2;i++)bo[s2[i]-'a']--;
        for(i=0;i<26;i++)sum+=abs(bo[i]);
        printf("Case #%d:  %d\n",tt,sum);
    }
    return 0;
}
