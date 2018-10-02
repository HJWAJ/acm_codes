#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int t,tt,len;
    char s[100],str[100];
    scanf("%d",&t);
    while(t--)
    {
        memset(s,0,sizeof(s));
        memset(str,0,sizeof(str));
        scanf("%d%s",&tt,s);
        strcpy(str,s);          
        len=strlen(s);
        next_permutation(s,s+len);
        if(strcmp(s,str)>0)printf("%d %s\n",tt,s);
        else printf("%d BIGGEST\n",tt);
    }
    
    //system("pause");    
    return 0;
}
