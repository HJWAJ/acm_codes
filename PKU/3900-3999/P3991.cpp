#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
    char s[10005],stack[10005];
    int len,ans,tt=0,i,top;
    while(scanf("%s",s) && s[0]!='-')
    {
        tt++;
        top=ans=0;
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(s[i]=='{')
            {
                stack[top]='{';
                top++;
            }
            else
            {
                if(top && stack[top-1]=='{')
                {
                    top--;
                }
                else
                {
                    stack[top]='}';
                    top++;
                }
            }
        }
        for(i=0;i<top;i+=2)
        {
            if(stack[i]=='{' && stack[i+1]=='{')ans++;
            else if(stack[i]=='}' && stack[i+1]=='}')ans++;
            else ans+=2;
        }
        printf("%d. %d\n",tt,ans);
    }
    return 0;
}
