#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int issub(char s[],char str[],int flag)
{
    int i;
    int len=strlen(s);
    int len1=strlen(str);
    if(len+flag>len1)return -1;
    for(i=0;i<len;i++)
        if(s[i]!=str[flag+i])return 0;
    return 1;     
}

int main()
{
    char str[500],s[100],buffer[500],lenstr,lens,flag,i;
    while(scanf("%s",str)!=EOF)
    {
        lenstr=strlen(str);
        while(scanf("%s",s) && strcmp(s,"END")!=0)
        {
            if(strcmp(s,"NULL")==0)
            {
                printf("0 NULL\n");
                continue;                   
            }
            lens=strlen(s);
            for(flag=0;flag<lenstr-lens+1;flag++)
            {
                if(issub(s,str,flag)==-1)
                {
                    printf("0 NULL\n");
                    break;                         
                }
                if(issub(s,str,flag)==1)
                {
                    if(flag==0)
                    {
                        printf("0 NULL\n");
                        goto label;
                    }
                    printf("%d ",flag);
                    for(i=0;i<flag;i++)printf("%c",str[i]);
                    printf("\n");
                    break;
                }          
            }
            if(flag==lenstr-lens+1)
            {
                printf("%d %s\n",lenstr,str);                       
            }
            label:;
            memset(s,0,sizeof(s));
            memset(buffer,0,sizeof(buffer));
        }
        memset(str,0,sizeof(str));
    }    
    
    return 0;
}
