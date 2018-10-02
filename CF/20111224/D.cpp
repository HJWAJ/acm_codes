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
char s[100005];
int has[10];
int bo[10];
char ss[2][100005];
int main()
{
    int len,i,flag=0,j;
    int cnt=0,cnt1=0,ans=0,cnt2=0,cnt3=0;
    scanf("%s",s);
    len=strlen(s);
    memset(has,0,sizeof(has));
    for(i=0;i<len;i++)has[s[i]-'0']++;
    memmove(bo,has,10);
    ans+=has[0];
    for(i=0;i<has[0];i++)ss[0][i]=ss[1][i]='0';
    flag=has[0];
    for(i=1;i<=5;i++)
        if(has[i] && bo[10-i])
        {
            has[i]--;
            bo[10-i]--;
            ss[0][flag]=i+'0';
            ss[1][flag]=10-i+'0';
            flag++;
            break;
        }
    //cout<<ss[0]<<' '<<ss[1]<<endl;
    if(i==6)
    {
        for(i=1;i<10;i++)
            for(j=1;j<10;j++)
                if(has[i] && bo[j] && i+j>10)
                {
                    ss[0][flag]=i;
                    ss[1][flag]=j;
                    flag++;
                    has[i]--;
                    bo[j]--;
                    goto label;
                }
    }
    label:;
    if(i==10 && j==10)
    {
        for(i=1;i<10;i++)
            while(has[i])
            {
                has[i]--;
                ss[0][flag]=i+'0';
                flag++;
            }
        for(i=1;i<10;i++)
            while(bo[i])
            {
                bo[i]--;
                ss[1][flag]=i+'0';
                flag++;
            }
        ss[0][flag]=ss[1][flag]='\0';
        puts(ss[0]);
        puts(ss[1]);
    }
    else
    {
        for(i=1;i<10;i++)
            while(has[i] && bo[9-i])
            {
                has[i]--;
                bo[9-i]--;
                ss[0][flag]=i+'0';
                ss[1][flag]=9-i+'0';
                flag++;
            }
        for(i=1;i<10;i++)
            while(has[i])
            {
                has[i]--;
                ss[0][flag]=i+'0';
                flag++;
            }
        for(i=1;i<10;i++)
            while(bo[i])
            {
                bo[i]--;
                ss[1][flag]=i+'0';
                flag++;
            }
        ss[0][flag]=ss[1][flag]='\0';
        puts(ss[0]);
        puts(ss[1]);
    }
    return 0;
}
