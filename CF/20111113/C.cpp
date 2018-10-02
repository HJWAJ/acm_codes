#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int prime[1000];
bool bo[10001];
int prime_table()
{
    int i,j,flag=0;
    memset(bo,0,sizeof(bo));
    bo[0]=bo[1]=1;
    for(i=2;i<=100;i++)
        if(!bo[i])
        {
            j=i*i;
            for(;j<=10000;j+=i)bo[j]=1;
        }
    for(i=0;i<=10000;i++)
        if(!bo[i])prime[flag++]=i;
    return flag;
}
int cnt[30];
char s[1005];
char ans[1005];
bool b[1005];
int main()
{
    int len,i,tmp,k,num,j;
    int flag=prime_table();
    scanf("%s",s);
    len=strlen(s);
    memset(cnt,0,sizeof(cnt));
    memset(ans,0,sizeof(ans));
    memset(b,0,sizeof(b));
    for(i=0;i<len;i++)cnt[s[i]-'a']++;
    for(i=0;i<flag;i++)
        if(prime[i]>len/2)break;
    flag=i;
    for(i=0;i<flag;i++)
    {
        tmp=prime[i];
        for(j=tmp;j<=len;j+=tmp)b[j]=1;
    }
    num=0;
    for(i=0;i<len;i++)
        if(b[i+1])num++;
    for(i=0;i<26;i++)
        if(cnt[i]>=num)
        {
            puts("YES");
            cnt[i]-=num;
            for(j=0;j<len;j++)
                if(b[j+1])ans[j]=char(i+'a');
            for(j=0;j<len;j++)
                if(ans[j]=='\0')
                {
                    for(k=0;k<26;k++)
                        if(cnt[k])
                        {
                            ans[j]=char(k+'a');
                            cnt[k]--;
                            break;
                        }
                }
            puts(ans);
            break;
        }
    if(i==26)puts("NO");
	return 0;
}
