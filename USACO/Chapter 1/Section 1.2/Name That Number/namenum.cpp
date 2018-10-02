/*
ID: hjw00002
PROG: namenum
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
using namespace std;

int map[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};

bool isequal(char s[],int flag[])
{
    int len=strlen(s),i;
    for(i=0;i<len;i++)
    {
        if((s[i]-'0')!=flag[i])return 0;                 
    }     
    return 1;
}

int main()
{
    int flag[5000][15],num=0,i,j;
    char dic[5000][15];
    int len[5000];
    memset(flag,0,sizeof(flag));
    memset(dic,0,sizeof(dic));
    memset(len,0,sizeof(len));
    freopen("dict.txt","r",stdin);
    
    while(scanf("%s",dic[num])!=EOF)
    {
        len[num]=strlen(dic[num]);
        for(i=0;i<len[num];i++)flag[num][i]=map[dic[num][i]-'A'];
        num++;
    }
    
    freopen("namenum.in","r",stdin);
    freopen("namenum.out","w",stdout);
    char s[15];
    memset(s,0,sizeof(s));
    scanf("%s",s);
    bool val=0;
    int leng=strlen(s);
    for(i=0;i<num;i++)
    {
        if(isequal(s,flag[i]) && leng==len[i]){val=1;printf("%s\n",dic[i]);}                  
    }
    if(val==0)printf("NONE\n");
    
    //system("pause");
    return 0;
}
