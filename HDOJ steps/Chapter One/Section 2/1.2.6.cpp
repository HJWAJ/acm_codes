#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int getnum1(char s[])
{
    int len=strlen(s)-2,flag=0;
    while(s[len]!='(')len--;
    len++;
    while(s[len]!=')')
    {
        flag*=10;
        flag+=(s[len]-'0');
        len++;                  
    }
    return flag;
}

int getnum2(char s[],int flag)
{
    int num=0,len=0;
    while(s[len]!='(')
    {
        num*=flag;
        num+=(s[len]-'0');
        len++;                  
    }    
    return num;
}

int main()
{
    int n,num,sum,flag,l1,l2;
    char s[1005];
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        while(n--)
        {
            scanf("%s",s);
            l1=0;
            flag=getnum1(s);
            num=getnum2(s,flag);
            sum+=num;
        }            
        printf("%d\n",sum);      
    }
    
    return 0;
}
