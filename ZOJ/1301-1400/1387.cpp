#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
char m[26][10]=
{
    ".-",//A
    "-...",//B
    "-.-.",//C
    "-..",//D
    ".",//E
    "..-.",//F
    "--.",//G
    "....",//H
    "..",//I
    ".---",//J
    "-.-",//K
    ".-..",//L
    "--",//M
    "-.",//N
    "---",//O
    ".--.",//P
    "--.-",//Q
    ".-.",//R
    "...",//S
    "-",//T
    "..-",//U
    "...-",//V
    ".--",//W
    "-..-",//X
    "-.--",//Y
    "--.."//Z
};
char str[10005];
char s[25];
char ss[10005][85];
int len[10005];
int dp[10005];
void gao(char *s,char *ss,int &len)
{
    int flag;
    char *mor,*start=ss;
    while(*s)
    {
        flag=(*s)-'A';
        mor=m[flag];
        while(*mor)
        {
            *ss=*mor;
            mor++;
            ss++;
        }
        s++;
    }
    *ss='\0';
    len=ss-start;
    ss=start;
}
bool match(int s,int n)
{
    int i;
    for(i=0;i<len[n];i++)
        if(str[s+i]!=ss[n][i])
            return 0;
    return 1;
}
int main()
{
    int t,n,i,j,flag;
    string sstr;
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        myset.clear();
        scanf("%s%d",str,&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            gao(s,ss[i],len[i]);
        }
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(i=1;str[i-1];i++)
            for(j=0;j<n;j++)
                if(i>=len[j] && dp[i-len[j]] && match(i-len[j],j))
                    dp[i]+=dp[i-len[j]];
        printf("%d\n",dp[i-1]);
    }
    return 0;
}
