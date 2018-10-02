#include<iostream>
#include<cstring>
#define N 1999
using namespace std;

int main()
{
    char ch,s[60001],str[30001];
    int flag=0,len,i;
    memset(s,0,sizeof(s));
    memset(str,0,sizeof(str));
    s[0]='0';
    while(gets(str))
    {
        strcat(s,str);
    }
    len=strlen(s)-1;
    if(len==0){printf("No\n");return 0;}
    for(i=2;i<=len;i++)flag=(flag+N)%i;    
    flag++;
    if(s[flag]=='?')printf("Yes\n");
    else if(s[flag]==' ')printf("No\n");
    else printf("No comments\n");
    
    system("pause");
    return 0;
}
