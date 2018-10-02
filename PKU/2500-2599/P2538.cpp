#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char map1[]={"`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,. "};
    char map2[]={"1234567890-=WERTYUIOP[]\\SDFGHJKL;\'XCVBNM,./ "};
    char s[10000],ans[10000];
    while(gets(s))
    {
        int len=strlen(s),i,flag;
        for(i=0;i<len;i++)
        {
            flag=0;
            while(map2[flag]!=s[i])flag++;
            ans[i]=map1[flag];   
        }
        printf("%s\n",ans);
        memset(ans,0,sizeof(ans));
        memset(s,0,sizeof(s));              
    }    
    
    return 0;
}
