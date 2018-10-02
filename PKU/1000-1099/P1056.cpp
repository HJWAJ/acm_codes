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
    int n=0,i,t=0;
    char s[20005][20];
    while(scanf("%s",s[n++])!=EOF)
    {
        if(s[n-1][0]=='9')
        {
            t++;
            qsort(s,n-1,sizeof(s[0]),cmp);
            for(i=0;i<n-2;i++)
                if(issub(s[i],s[i+1]))
                {
                    printf("Set %d is not immediately decodable\n",t);
                    break;
                }
            if(i==n-2)printf("Set %d is immediately decodable\n",t);
            n=0;
        }
    }
    return 0;
}
