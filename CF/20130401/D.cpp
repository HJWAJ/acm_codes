#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    char s[55];
    int n,len;
    scanf("%s%d",s,&n);
    len=strlen(s);
    for(int i=0;i<len;i++)
        if(s[i]<='Z')
            s[i]=s[i]-'A'+'a';
    for(int i=0;i<len;i++)
        if(s[i]<n+97)
            s[i]=s[i]-'a'+'A';
    puts(s);
    return 0;
}
