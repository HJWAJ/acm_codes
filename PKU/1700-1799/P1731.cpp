#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    char s[50005],s0[50005];
    int len;
    while(scanf("%s",s)!=EOF)
    {
        len=strlen(s);
        sort(s,s+len);
        strcpy(s0,s);
        while(1)
        {
            printf("%s\n",s);
            next_permutation(s,s+len);
            if(strcmp(s,s0)==0)break;
        }
        memset(s,0,sizeof(s));
        memset(s0,0,sizeof(s0));                         
    }
    
    return 0;
}
