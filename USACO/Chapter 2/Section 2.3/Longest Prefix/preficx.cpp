/*
ID: hjw00002
PROG: prefix
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
char dic[205][15];
int dlen[205];
char s[200200];
bool bo[200200];
int main()
{
    freopen("prefix.in","r",stdin);
    freopen("prefix.out","w",stdout);
    int i,j,flag=0,len;
    char tmp[1050];
    while(scanf("%s",dic[flag]) && strcmp(dic[flag],"."))
    {
        dlen[flag]=strlen(dic[flag]);
        flag++;
    }
    memset(s,0,sizeof(s));
    while(scanf("%s",tmp)!=EOF)strcat(s,tmp);
    len=strlen(s);
    memset(bo,0,sizeof(bo));
    bo[0]=1;
    for(i=1;i<=len;i++)
        for(j=0;j<flag;j++)
            if(i-dlen[j]>=0 && bo[i-dlen[j]] && !strncmp(s+i-dlen[j],dic[j],dlen[j]))bo[i]=1;
    for(i=len;i>=0;i--)
        if(bo[i])
        {
            printf("%d\n",i);
            break;
        }
    return 0;
}
