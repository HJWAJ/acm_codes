#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<fstream>
using namespace std;
char s[105][105];
int leng[105];
char str[205];
char ch[2];
bool bo[105];
bool bo1[105];
int n;
int main()
{
    int i,j,k,len;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",s[i]);
        leng[i]=strlen(s[i]);
        for(j=0;j<leng[i];j++)
            if(s[i][j]>='A' && s[i][j]<='Z')s[i][j]=s[i][j]-'A'+'a';
    }
    scanf("%s%s",str,ch);
    if(ch[0]>='A' && ch[0]<='Z')ch[0]=ch[0]-'A'+'a';
    memset(bo,0,sizeof(bo));
    memset(bo1,0,sizeof(bo1));
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]>='A' &&str[i]<='Z')
        {
            str[i]=(str[i]-'A'+'a');
            bo[i]=1;
        }
    }
    for(i=0;i<len;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i+leng[j]>len)continue;
            else
            {
                for(k=i;k<i+leng[j];k++)
                    if(str[k]!=s[j][k-i])break;
                if(k==i+leng[j])
                    for(k=i;k<i+leng[j];k++)bo1[k]=1;
            }
        }
    }
    for(i=0;i<len;i++)
    {
        if(bo1[i])
        {
            if(str[i]!=ch[0])str[i]=ch[0];
            else if(ch[0]=='a')str[i]='b';
            else str[i]='a';
        }
    }
    for(i=0;i<len;i++)
    {
        if(bo[i])str[i]=str[i]-'a'+'A';
    }
    puts(str);
    return 0;
}
