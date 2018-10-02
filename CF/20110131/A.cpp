#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char s[105];
    char str[]="hello";
    scanf("%s",s);
    int i=0,j,len=strlen(s);
    for(j=0;j<len;j++)
    {
        if(s[j]==str[i])i++;
        if(i==5)break;                  
    }         
    if(i==5)printf("YES\n");
    else printf("NO\n");
    
    return 0;
}
