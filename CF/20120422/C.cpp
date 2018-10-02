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
int a[100005],b[100005];
char s[100005];
int main()
{
    int cnt1=0,cnt2=0,i;
    int len,num,cnt=99999999;
    scanf("%s",s);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        a[i]=cnt1;
        if(s[i]>='a')cnt1++;
    }
    for(i=len-1;i>=0;i--)
    {
        b[i]=cnt2;
        if(s[i]<'a')cnt2++;
    }
    for(i=0;i<len;i++)
        if(a[i]+b[i]<cnt)
            cnt=a[i]+b[i];
    printf("%d\n",cnt);
    return 0;
}
