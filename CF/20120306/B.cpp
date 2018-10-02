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
char s[205];
int main()
{
    int n,i,flag;
    scanf("%d%s",&n,s);
    if(n==1)
    {
        if(s[0]==s[1])puts("NO");
        else puts("YES");
        return 0;
    }
    sort(s,s+n);
    sort(s+n,s+n*2);
    if(s[0]==s[n])
    {
        puts("NO");
        return 0;
    }
    else if(s[0]>s[n])flag=1;
    else flag=-1;
    for(i=1;i<n;i++)
    {
        if(s[i]==s[i+n])
        {
            puts("NO");
            return 0;
        }
        else if(s[i]>s[i+n] && flag==-1)
        {
            puts("NO");
            return 0;
        }
        else if(s[i]<s[i+n] && flag==1)
        {
            puts("NO");
            return 0;
        }
        else continue;
    }
    puts("YES");
    return 0;
}
