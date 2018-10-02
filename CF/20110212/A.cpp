#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char s[1000],cnt1=0,cnt2=0;
    scanf("%s",s);
    int len=strlen(s),i;
    for(i=0;i<len;i++)
        if(s[i]<='Z')cnt1++;
        else cnt2++;
    if(cnt1>cnt2)
        for(i=0;i<len;i++)
        {
            if(s[i]>'Z')printf("%c",s[i]-'a'+'A');
            else printf("%c",s[i]);                  
        }
    else
        for(i=0;i<len;i++)
        {
            if(s[i]<='Z')printf("%c",s[i]-'A'+'a');
            else printf("%c",s[i]);                  
        }
    printf("\n");
    
    return 0;
}
