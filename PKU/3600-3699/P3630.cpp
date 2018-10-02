#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int cmp(const void *p,const void *q)
{
    char *a=(char *)p;
    char *b=(char *)q;
    return strcmp(a,b);
}

bool issub(char a[],char b[])
{
    int len1=strlen(a),len2=strlen(b),i;
    if(a>b)return 0;
    for(i=0;i<len1;i++)
        if(a[i]!=b[i])return 0;
    return 1;
}

int main()
{
    int t,n,i;
    char s[20005][20];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%s",s[i]);
        qsort(s,n,sizeof(s[0]),cmp);
        for(i=0;i<n-1;i++)
        {
            if(issub(s[i],s[i+1]))
            {
                printf("NO\n");
                break;
            }
        }
        if(i==n-1)printf("YES\n");
    }
    return 0;
}
