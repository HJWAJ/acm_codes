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
    int n,i;
    char s[55];
    scanf("%d%s",&n,s);
    int len=strlen(s);
    for(i=0;i<len;i++)
        if(s[i]!='4' && s[i]!='7')
            break;
    if(i!=len)
    {
        puts("NO");
    }
    else
    {
        int sum1=0,sum2=0;
        for(i=0;i<len/2;i++)sum1+=s[i];
        for(;i<len;i++)sum2+=s[i];
        if(sum1==sum2)puts("YES");
        else puts("NO");
    }
    return 0;
}
