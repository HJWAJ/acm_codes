#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
char s[1005],ans[2005];
int a[1005],b[2005];
int change(char ch)
{
    if(ch<'A')return ch-'0';
    else if(ch<'a')return ch-'A'+10;
    else return ch-'a'+36;
}
char exchange(int num)
{
    if(num<10)return char(num+'0');
    else if(num<36)return char(num-10+'A');
    else return char(num-36+'a');
}
int div(int a[],int p,int q,int len)
{
    int mod,i;
    for(i=0;i<len-1;i++)
    {
        a[i+1]+=a[i]%q*p;
        a[i]/=q;
    }
    mod=a[len-1]%q;
    a[len-1]/=q;
    return mod;
}
bool chk(int a[],int len)
{
    int i;
    for(i=0;i<len;i++)
        if(a[i])return 1;
    return 0;
}
void rev(char s[],int len)
{
    int i;
    for(i=0;i<len/2;i++)swap(s[i],s[len-1-i]);
}
int main()
{
    int t,p,q,len,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%s",&p,&q,s);
        printf("%d %s\n",p,s);
        if(!strcmp(s,"0"))
        {
            printf("%d 0\n\n",q);
            continue;
        }
        len=strlen(s);
        for(i=0;i<len;i++)a[i]=change(s[i]);
        i=0;
        while(chk(a,len))b[i++]=div(a,p,q,len);
        len=i;
        for(i=0;i<len;i++)ans[i]=exchange(b[i]);
        rev(ans,len);
        ans[len]='\0';
        printf("%d %s\n\n",q,ans);
    }
    return 0;
}

