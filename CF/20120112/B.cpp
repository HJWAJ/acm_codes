#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int flag=0;
char s[105];
char ans[205];
int main()
{
    scanf("%s",s);
    if(s[0]=='-')
    {
        strcpy(s,s+1);
        flag=1;
    }
    int len=strlen(s);
    int i=0;
    while(s[i]!='.' && i!=len)i++;
    int j;
    if(i%3==0)
    {
        ans[0]=s[0];
        ans[1]=s[1];
        ans[2]=s[2];
        j=3;
    }
    else if(i%3==1)
    {
        ans[0]=s[0];
        j=1;
    }
    else if(i%3==2)
    {
        ans[0]=s[0];
        ans[1]=s[1];
        j=2;
    }
    int k=j;
    for(;j<i;j+=3)
    {
        ans[k]=',';
        ans[k+1]=s[j];
        ans[k+2]=s[j+1];
        ans[k+3]=s[j+2];
        k+=4;
    }
    ans[k]='.';
    k++;
    if(s[i]=='.')
    {
        if(i<len-2)
        {
            ans[k]=s[i+1];
            ans[k+1]=s[i+2];
        }
        else if(i<len-1)
        {
            ans[k]=s[i+1];
            ans[k+1]='0';
        }
        else
        {
            ans[k]=ans[k+1]='0';
        }
    }
    else
    {
        ans[k]=ans[k+1]='0';
    }
    ans[k+2]='\0';
    if(!flag)printf("$%s\n",ans);
    else printf("($%s)\n",ans);
    return 0;
}
