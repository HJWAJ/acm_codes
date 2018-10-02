#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
char s[2010],begin[2010],end[2010];
int st[2010],en[2010],stflag=0,enflag=0;
set<string> sset;
bool check(char s[],char s1[],int len)
{
    int i;
    for(i=0;i<len;i++)
        if(s[i]!=s1[i])return 0;
    return 1;
}
int main()
{
    int len,len1,len2,i,j,k,cnt=0;
    string tmp;
    scanf("%s%s%s",s,begin,end);
    len=strlen(s);
    len1=strlen(begin);
    len2=strlen(end);
    for(i=0;i<len-len1+1;i++)
    {
        if(check(s+i,begin,len1))st[stflag++]=i;
        if(check(s+i,end,len2))en[enflag++]=i;
    }
    for(i=0;i<stflag;i++)
        for(j=0;j<enflag;j++)
            if(st[i]<=en[j] && st[i]+len1<=en[i]+len2)
            {
                for(k=st[i];k<en[i]+len2-st[i];k++)tmp.push_back(s[k]);
                pair< set<string>::iterator, bool > p=sset.insert(tmp);
                if(p.second)cnt++;
            }
    printf("%d\n",cnt);
    return 0;
}
