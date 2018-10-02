#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std;
int main()
{
    char s[105];
    scanf("%s",s);
    int len=strlen(s),i;
    for(i=1;i<len;i++)
        if(s[i]>'Z')
            break;
    if(i==len)
        for(i=0;i<len;i++)
        {
            if(s[i]>'Z')s[i]=s[i]-'a'+'A';
            else s[i]=s[i]-'A'+'a';
        }
    puts(s);
    return 0;
}
