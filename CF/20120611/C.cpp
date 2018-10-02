#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
#include<windows.h>
using namespace std;
string stk[100005];
int top=0;
char s[200005];
char buffer[200005];
bool bo[200005];
char ans[200005];
char throws[200005];
bool isletter(char ch)
{
    if(ch>='A' && ch<='Z')return 1;
    if(ch>='a' && ch<='z')return 1;
    return 0;
}
int main()
{
    int n,len,i,buf,j;
    bool flag2=0,flag=0;
    scanf("%d",&n);
    gets(s);
    while(n--)
    {
        gets(s);
        len=strlen(s);
        i=0;
        while(!isletter(s[i]) && i<len)i++;
        if(i==len)continue;
        buf=0;
        while(isletter(s[i]))
        {
            buffer[buf++]=s[i++];
        }
        buffer[buf]='\0';
        if(!strcmp(buffer,"try"))
        {
            top++;
            continue;
        }
        else if(!strcmp(buffer,"throw"))
        {
            while(!isletter(s[i]))i++;
            buf=0;
            while(isletter(s[i]))
            {
                buffer[buf++]=s[i++];
            }
            buffer[buf]='\0';
            strcpy(throws,buffer);
            for(j=0;j<top;j++)bo[j]=1;
            flag=1;
            continue;
        }
        else//catch
        {
            while(!isletter(s[i]))i++;
            buf=0;
            while(isletter(s[i]))
            {
                buffer[buf++]=s[i++];
            }
            buffer[buf]='\0';
            if(flag && !strcmp(throws,buffer) && bo[top-1])
            {
                while(s[i]!='"')i++;
                i++;
                buf=0;
                while(s[i]!='"')
                {
                    buffer[buf++]=s[i++];
                }
                buffer[buf]='\0';
                //cout<<bo[0]<<' '<<bo[1]<<endl;
                puts(buffer);
                return 0;
            }
            else if(flag && strcmp(throws,buffer) && bo[top-1])
            {
                bo[top-1]=0;
                //cout<<bo[1]<<endl;
            }
            top--;
        }
    }
    puts("Unhandled Exception");
    return 0;
}
