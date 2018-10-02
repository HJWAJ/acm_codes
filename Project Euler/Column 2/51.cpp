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
int prime[200000];
bool bo[1000001];
int prime_table()
{
    int i,j,flag=0;
    memset(bo,0,sizeof(bo));
    bo[0]=bo[1]=1;
    for(i=2;i<=1000;i++)
        if(!bo[i])
        {
            j=i*i;
            for(;j<=1000000;j+=i)bo[j]=1;
        }
    for(i=0;i<=1000000;i++)
        if(!bo[i])prime[flag++]=i;
    return flag;
}
int getnum(int n)
{
    int boo[10],i;
    memset(boo,0,sizeof(boo));
    while(n)
    {
        boo[n%10]++;
        n/=10;
    }
    int max=-1;
    for(i=0;i<10;i++)
        if(max<boo[i])max=boo[i];
    return max;
}
bool is(int n)
{
    int boo[10],i,j;
    char s[15],ss[15];
    int len=0,cnt=0;
    memset(boo,0,sizeof(boo));
    while(n)
    {
        boo[n%10]++;
        s[len++]=n%10+'0';
        n/=10;
    }
    s[len]='\0';
    int max=-1,tmp,maxi;
    for(i=0;i<10;i++)
        if(max<boo[i])
        {
            max=boo[i];
            maxi=i;
        }
    for(i=0;i<10;i++)
    {
        memcpy(ss,s,sizeof(s));
        for(j=0;j<len;j++)
            if(ss[j]==maxi+'0')
                ss[j]=i+'0';
        tmp=0;
        for(j=len-1;j>=0;j--)
        {
            tmp*=10;
            tmp+=ss[j]-'0';
        }
        if(!bo[tmp] && ss[len-1]!='0')cnt++;
    }
    if(cnt>7)
    {
        //cout<<cnt<<' '<<tmp<<endl;
        return 1;
    }
    return 0;
}
int main()
{
    int flag=prime_table(),i;
    for(i=0;i<flag;i++)
        if(getnum(prime[i])>=3)
        {
            if(is(prime[i]))
            {
                printf("%d\n",prime[i]);
                break;
            }
        }
    return 0;
}
