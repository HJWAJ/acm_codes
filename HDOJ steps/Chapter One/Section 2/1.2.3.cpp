#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void rev(char s[])
{
    int len=strlen(s),i;
    for(i=0;i<len/2;i++)swap(s[i],s[len-1-i]);     
}

int main()
{
    char s[1005],tmp[1005];
    int len,n,flag,i;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(s);
        len=strlen(s);
        s[len]='\n';
        flag=0;
        memset(tmp,0,sizeof(tmp));
        for(i=0;i<=len;i++)
        {
            if(s[i]!=' ' && s[i]!='\n')tmp[flag++]=s[i];
            else
            {
                rev(tmp);
                if(s[i]==' ')printf("%s ",tmp);
                else printf("%s\n",tmp);
                flag=0;
                memset(tmp,0,sizeof(tmp));
            }
        }          
    }
    
    return 0;
}
