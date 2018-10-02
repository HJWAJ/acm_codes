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
using namespace std;
int main()
{
    char s[15],max='0';
    int a,b,i=0,j,len1,len;
    bool flag=0;
    scanf("%s",s);
    len=strlen(s);
    while(s[i]!=':')i++;
    len1=i;
    for(i=0;i<len1-1;i++)
        if(s[i]!='0')break;
    if(i==len1-1)
    {
        for(i=len1+1;i<len-1;i++)
            if(s[i]!='0')break;
        if(i==len-1)
        {
            if(s[len1-1]<'A'+14)
            {
                puts("-1");
                //while(1);
                return 0;
            }
            else
            {
                puts("0");
                //while(1);
                return 0;
            }
        }
    }
    for(i=0;i<len1;i++)
        if(s[i]>max)max=s[i];
    for(i=len1+1;i<len;i++)
        if(s[i]>max)max=s[i];
    if(max>='A')max=max-'A'+10;
    else max-='0';
    for(i=max+1;i<=60;i++)
    {
        a=b=0;
        for(j=0;j<len1;j++)
        {
            if(s[j]<'A')
            {
                a*=i;
                a+=s[j]-'0';
            }
            else
            {
                a*=i;
                a+=s[j]-'A'+10;
            }
        }
        for(j=len1+1;j<len;j++)
        {
            if(s[j]<'A')
            {
                b*=i;
                b+=s[j]-'0';
            }
            else
            {
                b*=i;
                b+=s[j]-'A'+10;
            }
        }
        if(a<24 && b<60)
        {
            printf("%d ",i);
            flag=1;
        }
    }
    if(flag)puts("");
    else puts("0");
    //while(1);
    return 0;
}
