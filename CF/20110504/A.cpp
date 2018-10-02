#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char str[200005],s[200005];
    int flag=1,len,i;
    scanf("%s",str);
    len=strlen(str);
    s[0]=str[0];
    for(i=1;i<len;i++)
    {
        if(s[flag-1]==str[i])flag--;
        else s[flag++]=str[i];            
    }
    for(i=0;i<flag;i++)printf("%c",s[i]);
    printf("\n");
    
    //system("pause");
    return 0;
}
