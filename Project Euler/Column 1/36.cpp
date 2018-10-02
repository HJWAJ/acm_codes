//构造10进制检验2进制 

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
void rev(char s[],char s1[])
{
    int len=strlen(s);
    for(int i=0;i<len;i++)s1[i]=s[len-1-i];
}
bool is(int n)
{
    char s[2][105];
    memset(s,0,sizeof(s));
    int len=0;
    while(n)
    {
        s[0][len]=char((n&1)+'0');
        len++;
        n>>=1;
    }
    rev(s[0],s[1]);
    if(!strcmp(s[0],s[1]))return 1;
    return 0;
}
int main()
{
    int i,j,k,sum=0,tmp;
    for(i=1;i<10;i++)
    {
        if(is(i))sum+=i;
        tmp=i*11;
        if(is(tmp))sum+=tmp;
    }
    for(i=1;i<10;i++)
        for(j=0;j<10;j++)
        {
            tmp=i*101+j*10;
            if(is(tmp))sum+=tmp;
            tmp=i*1001+j*110;
            if(is(tmp))sum+=tmp;
        }
    for(i=1;i<10;i++)
        for(j=0;j<10;j++)
            for(k=0;k<10;k++)
            {
                tmp=i*10001+j*1010+k*100;
                if(is(tmp))sum+=tmp;
                tmp=i*100001+j*10010+k*1100;
                if(is(tmp))sum+=tmp;
            }
    printf("%d\n",sum);
    return 0;
}
