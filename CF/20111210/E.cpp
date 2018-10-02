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
char s[100050];
int main()
{
    int a=0,b=0,c=0,i,len,tmp1,tmp2;
    scanf("%s",s);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='0')a++;
        else if(s[i]=='1')b++;
        else c++;
    }
    if(a+c>b)puts("00");
    tmp1=len/2-a;
    tmp2=(len+1)/2-b;
    if(tmp1>=0 && tmp2>=0)
    {
        if(s[len-1]=='1' || (s[len-1]=='?' && tmp2))puts("01");
        if(s[len-1]=='0' || (s[len-1]=='?' && tmp1))puts("10");
    }
    if(b+c>a+1)puts("11");
    return 0;
}
