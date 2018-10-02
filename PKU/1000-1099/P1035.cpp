#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<fstream>
using namespace std;
char dic[10005][20],s[20];
void mystrcmp(char s[],char s1[])
{
    int len=strlen(s),len1=strlen(s1),i,j,flag;
    if(len>len1 && len-len1>1)return ;
    if(len<len1 && len1-len>1)return ;
    if(len>len1 && len-len1==1)
    {
        flag=0;
        for(i=0,j=0;j<len1;i++,j++)
        {
            if(s[i]!=s1[j] && flag==0)
            {
                i++;
                flag=1;
            }
            if(s[i]!=s1[j] && flag==1)return ;
        }
        printf(" %s",s1);
        return ;
    }
    if(len<len1 && len1-len==1)
    {
        flag=0;
        for(i=0,j=0;i<len;i++,j++)
        {
            if(s[i]!=s1[j] && flag==0)
            {
                j++;
                flag=1;
            }
            if(s[i]!=s1[j] && flag==1)return ;
        }
        printf(" %s",s1);
        return ;
    }
    if(len==len1)
    {
        flag=0;
        for(i=0;i<len;i++)
        {
            if(s[i]!=s1[i] && flag==0)
            {
                flag=1;
                i++;
            }
            if(s[i]!=s1[i] && flag==1)return;
        }
        printf(" %s",s1);
        return ;
    }
}
int main()
{
    int cnt=0,i,len;
    while(scanf("%s",dic[cnt]) && strcmp(dic[cnt],"#"))cnt++;
    while(scanf("%s",s) && strcmp(s,"#"))
    {
        for(i=0;i<cnt;i++)
            if(strcmp(dic[i],s)==0)
            {
                printf("%s is correct\n",s);
                break;
            }
        if(i!=cnt)continue;
        else
        {
            printf("%s:",s);
            len=strlen(s);
            for(i=0;i<cnt;i++)mystrcmp(s,dic[i]);
            puts("");
        }
    }
    return 0;
}
