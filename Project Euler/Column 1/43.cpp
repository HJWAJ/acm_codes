#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
using namespace std;
char s[]="0123456789",ss[]="0123456789";
int pri[]={2,3,5,7,11,13,17};
long long sum=0;
long long check(char s[])
{
    int i,tmp;
    for(i=0;i<7;i++)
    {
        tmp=(s[i+1]-'0')*100+(s[i+2]-'0')*10+(s[i+3]-'0');
        if(tmp%pri[i])return 0;
    }
    return 1;
}
long long getnum(char s[])
{
    int i;
    long long res=0;
    for(i=0;i<10;i++)
    {
        res*=10;
        res+=(s[i]-'0');
    }
    return res;
}
int main()
{
    do
    {
        if(check(s))sum+=getnum(s);
        next_permutation(s,s+10);
    }while(strcmp(s,ss)==1);
    printf("%lld\n",sum);
    return 0;
}
