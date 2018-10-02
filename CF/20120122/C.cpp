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
char a[100005],b[100005];
int max(int m,int n)
{
    return m>n?m:n;
}
int main()
{
    int i,aa=0,bb=0,len;
    scanf("%s%s",a,b);
    len=strlen(a);
    for(i=0;i<len;i++)
        if(a[i]!=b[i])
        {
            if(a[i]=='4')aa++;
            else bb++;
        }
    printf("%d\n",max(aa,bb));
    return 0;
}
