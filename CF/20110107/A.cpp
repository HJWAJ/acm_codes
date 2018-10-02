#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

bool issub(char str[],char s[])
{
    int len=strlen(str);
    int leng=strlen(s);
    if(len>leng)return 0;
    int i;
    for(i=0;i<len;i++)
    {
        if(str[i]!=s[i])return 0;                  
    }     
    return 1;
}

char* min(char str1[],char str2[])
{
    //char strmin[105];
    int i=0;
    while(str1[i]!='\0' && str2[i]!='\0')
    {
        if(str1[i]<str2[i])return str1;
        if(str1[i]>str2[i])return str2;
        i++;                  
    }      
    int len1=strlen(str1);
    int len2=strlen(str2);
    if(len1<len2)return str1;
    return str2;
}

int main()
{
    char str[105],s[105][105];
    while(scanf("%s",str)!=EOF)
    {
        int n,i,len=strlen(str);
        int val=0;
        scanf("%d",&n);
        char strmin[105];
        memset(strmin,'z',105);
        //printf("%s",strmin);
        for(i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            if(issub(str,s[i])){strcpy(strmin,min(strmin,s[i]));val=1;}                
        }                           
        if(val==0)printf("%s\n",str);
        else printf("%s\n",strmin);
    }    
    
    return 0;
}
