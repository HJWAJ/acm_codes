#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main()
{
    char s1[1005],s2[1005];
    int a1[30],a2[30];
    int len1,len2,i,j;
    scanf("%s%s",s1,s2);
    len1=strlen(s1);
    len2=strlen(s2);
    if(len1!=len2)puts("NO");
    else
    {
        memset(a1,0,sizeof(a1));
        memset(a2,0,sizeof(a2));
        for(i=0;i<len1;i++)
        {
            a1[s1[i]-'A']++;
            a2[s2[i]-'A']++;
        }
        for(i=0;i<26;i++)
        {
            for(j=0;j<26;j++)
                if(a1[i]==a2[j])
                {
                    a2[j]=0;
                    break;
                }
            if(j==26)
            {
                puts("NO");
                break;
            }
        }
        if(i==26)puts("YES");
    }
    return 0;
}
