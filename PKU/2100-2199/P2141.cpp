#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char map[2][30];
    char s[10000];
    int i;
    scanf("%s",map[0]);
    getchar();
    for(i=0;i<26;i++)map[1][i]=char(map[0][i]-'a'+'A');
    gets(s);
    int len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]>='A' && s[i]<='Z')s[i]=map[1][s[i]-'A'];
        else if(s[i]!=' ')s[i]=map[0][s[i]-'a'];              
    }
    printf("%s\n",s);
    
    return 0;
}
