#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<vector>
using namespace std;
bool isv(char ch)
{
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='y')return 1;
    return 0;
}
int main()
{
    char s[105];
    int len,i,j;
    scanf("%s",s);
    len=strlen(s);
    for(i=j=0;i<len;i++)
    {
        if(s[i]<'a')s[i]=s[i]-'A'+'a';
        if(!isv(s[i]))s[j++]=s[i];
    }
    for(i=0;i<j;i++)printf(".%c",s[i]);
    puts("");
    return 0;
}
