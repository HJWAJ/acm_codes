#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    char s1[105],s2[105];
    scanf("%s%s",s1,s2);
    int len1=strlen(s1),len2=strlen(s2),i;
    for(i=0;i<len1;i++)
        if(s1[i]<'a')s1[i]=s1[i]-'A'+'a';
    for(i=0;i<len2;i++)
        if(s2[i]<'a')s2[i]=s2[i]-'A'+'a';
    printf("%d\n",strcmp(s1,s2));
}
