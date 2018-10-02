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
char s[100005];
char ans[100005];
int bo[26];
int main()
{
    int len,i,ansl=0;
    int flag;
    scanf("%s",s);
    len=strlen(s);
    memset(bo,0,sizeof(bo));
    for(i=0;i<len;i++)bo[s[i]-'a']++;
    i=0;
    for(flag=25;flag>=0;flag--)
    {
        if(bo[flag])
        {
            //cout<<flag<<' '<<i<<endl;
            for(;i<len;)
            {
                if(s[i]-'a'<flag)
                {
                    bo[s[i]-'a']--;
                    i++;
                    continue;
                }
                else
                {
                    //cout<<i<<endl;
                    ans[ansl++]=s[i];
                    bo[flag]--;
                    i++;
                    while(bo[flag])
                    {
                        if(s[i]-'a'==flag)ans[ansl++]=s[i];
                        bo[s[i]-'a']--;
                        //cout<<s[i]-'a'<<' '<<bo[s[i]-'a']<<' '<<i<<endl;
                        i++;
                    }
                    break;
                }
            }
        }
    }
    ans[ansl]='\0';
    puts(ans);
    return 0;
}
