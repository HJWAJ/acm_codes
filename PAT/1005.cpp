#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
char s[105];
const char en[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main()
{
    int sum=0,len;
    scanf("%s",s);
    len=strlen(s);
    for(int i=0;i<len;i++)sum+=s[i]-'0';
    sprintf(s,"%d",sum);
    len=strlen(s);
    for(int i=0;i<len-1;i++)printf("%s ",en[s[i]-'0']);
    puts(en[s[len-1]-'0']);
    return 0;
}
