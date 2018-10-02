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
char s[1005];
int len,i;
char ans[1005];
int cnt;
bool isBig(char ch)
{
    return ch>='A' && ch<='Z';
}
bool isSmall(char ch)
{
    return ch>='a' && ch<='z';
}
bool ok1()
{
    if(isBig(s[0]) || s[0]=='_' || s[len-1]=='_')return 1;
    int flag=0;
    for(i=0;i<len;i++)
    {
        if(isBig(s[i]))flag|=1;
        if(s[i]=='_')flag|=2;
    }
    if(flag==3)return 1;
    for(i=0;i<len-1;i++)
        if(s[i]=='_' && s[i+1]=='_')
            return 1;
    return 0;
}
bool ok2()
{
    int flag=0;
    for(i=0;i<len;i++)
    {
        if(isBig(s[i]))flag|=1;
        if(s[i]=='_')flag|=2;
    }
    if(flag==1)return 1;
    return 0;
}
bool ok3()
{
    int flag=0;
    for(i=0;i<len;i++)
    {
        if(isBig(s[i]))flag|=1;
        if(s[i]=='_')flag|=2;
    }
    if(flag==2)return 1;
    return 0;
}
void gao1()
{
    int flag=0;
    cnt=0;
    for(i=0;i<len;i++)
    {
        if(isSmall(s[i]))
        {
            if(flag)ans[cnt++]=s[i]-'a'+'A';
            else ans[cnt++]=s[i];
            flag=0;
        }
        else flag=1;
    }
    ans[cnt]='\0';
    puts(ans);
}
void gao2()
{
    cnt=0;
    for(i=0;i<len;i++)
    {
        if(isBig(s[i]))
        {
            ans[cnt++]='_';
            ans[cnt++]=s[i]-'A'+'a';
        }
        else ans[cnt++]=s[i];
    }
    ans[cnt]='\0';
    puts(ans);
}
int main()
{
    gets(s);
    len=strlen(s);
    if(ok1())puts("Error!");
    else if(ok2())gao2();
    else if(ok3())gao1();
    else puts(s);
    return 0;
}
