#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<vector>
using namespace std;
char s[15];
char tmp[15];
char ans[15];
bool pal(int a)
{
    char ss[15];
    memset(ss,0,sizeof(ss));
    memset(tmp,0,sizeof(tmp));
    int l=0,len=strlen(s),i;
    for(i=0;i<len;i++)
        if(a&(1<<i))
            ss[l++]=s[i];
    for(i=0;i<l;i++)
        if(ss[i]!=ss[l-1-i])
            return 0;
    strcpy(tmp,ss);
    return 1;
}
int main()
{
    int i,len,n;
    scanf("%s",s);
    len=strlen(s);
    n=(1<<len);
    for(i=0;i<n;i++)
        if(pal(i))
        {
            if(strcmp(tmp,ans)>0)
            {
                memset(ans,0,sizeof(ans));
                strcpy(ans,tmp);
            }
        }
    puts(ans);
    return 0;
}
