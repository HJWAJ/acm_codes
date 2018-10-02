#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1005];
char s[1005];
int main()
{
    int n,i,len,tmp;
    bool used;
    while(scanf("%s",s)!=EOF)
    {
        len=strlen(s);
        n=0;tmp=0;i=0;
        used=false;
        for(;i<len;i++)
        {
            if(s[i]!='5')
            {
                used=true;
                tmp*=10;
                tmp+=s[i]-'0';
            }
            else
            {
                if(used)
                {
                    a[n++]=tmp;
                    tmp=0;
                    used=false;
                }
            }
        }
        if(used)a[n++]=tmp;
        sort(a,a+n);
        for(i=0;i<n-1;i++)printf("%d ",a[i]);
        printf("%d\n",a[i]);
    }
    return 0;
}
