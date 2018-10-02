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
using namespace std;
char s[100005],t[100005];
int main()
{
    int len1,len2,i,x,y;
    scanf("%s%s",s,t);
    len1=strlen(s);
    len2=strlen(t);
    if(len1!=len2)
    {
        puts("NO");
        return 0;
    }
    int cnt=0;
    for(i=0;i<len1;i++)
        if(s[i]!=t[i])
        {
            cnt++;
            if(cnt==1)x=i;
            else if(cnt==2)y=i;
            else
            {
                puts("NO");
                return 0;
            }
        }
    if(cnt==0)
    {
        puts("YES");
        return 0;
    }
    if(cnt==1)
    {
        puts("NO");
        return 0;
    }
    swap(s[x],s[y]);
    if(!strcmp(s,t))
    {
        puts("YES");
    }
    else puts("NO");
    return 0;
}
